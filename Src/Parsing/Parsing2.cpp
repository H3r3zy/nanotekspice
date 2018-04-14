/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include <Parsing/Parsing2.hpp>
#include "Parsing2.hpp"
#include "AbstractComponent.hpp"
#include "CD4008BMS.hpp"
#include "CD4011B.hpp"
#include "HEF4001B.hpp"
#include "Input.hpp"
#include "Clock.hpp"
#include "CD4030C.hpp"
#include "CD4069UBC.hpp"
#include "HCF4081B.hpp"
#include "HEF4071B.hpp"
#include "CD4512B.hpp"
#include "CD4514BC.hpp"
#include "MC14040B.hpp"
#include "HC4017.hpp"
#include "Output.hpp"
#include "CD4013BC.hpp"
#include "CD4094BC.hpp"
#include "ErrorParsing.hpp"

nts::Parsing::Parsing(std::string &fileName, char **&av)
{
	factory.add("input", new nts::Input());
	factory.add("output", new nts::Output());
	factory.add("true", new nts::Input());
	factory.add("false", new nts::Input());
	factory.add("clock", new nts::Clock());
	//factory.add("2716", new nts::Input());
	factory.add("4001", new nts::HEF4001B());
	factory.add("4008", new nts::CD4008BMS());
	factory.add("4011", new nts::CD4011B());
	factory.add("4013", new nts::CD4013BC());
	factory.add("4017", new nts::HC4017());
	factory.add("4030", new nts::CD4030C());
	factory.add("4040", new nts::MC14040B());
	factory.add("4069", new nts::CD4069UBC());
	factory.add("4071", new nts::HEF4071B());
	factory.add("4081", new nts::HCF4081B());
	factory.add("4094", new nts::CD4094BC());
	//factory.add("4503", new nts::CD4011B());
	factory.add("4512", new nts::CD4512B());
	factory.add("4514", new nts::CD4514BC());
	//factory.add("i4004", new nts::CD4011B());
	//factory.add("mk4801", new nts::CD4011B());

	_file = std::ifstream(fileName.c_str());
	if (!_file)
		throw nts::errorParsing("Bad file given as arguments: ", fileName);
	verifArg(av);
	while (getline(_file, _line))
		parseLine();
	setLinks();
}

nts::Parsing::~Parsing()
{
	for (auto &it: _components) {
		delete it.second;
	}
}

std::map<std::string, nts::IComponent *> &nts::Parsing::getComponents()
{
	return _components;
}

std::map<std::string, nts::Input *> &nts::Parsing::getInputs()
{
	return _inputs;
}

std::map<std::string, nts::Output *> &nts::Parsing::getOutputs()
{
	return _outputs;
}

std::map<std::string, nts::Clock *> &nts::Parsing::getClocks()
{
	return _clocks;
}

void nts::Parsing::verifArg(char **&arg)
{
	for (unsigned int i = 2; arg[i]; i++) {
		std::regex pattern("(\\w+)=(\\d)");
		std::smatch groupes;
		std::string actual(arg[i]);

		if (std::regex_search(actual, groupes, pattern)) {
			_arguments[groupes[1].str()] = groupes[2].str();
		} else
			throw nts::errorParsing("Bad argument: ", arg[i]);
	}
}

bool nts::Parsing::checkSection() {
	bool ret = false;

	for (auto &it: _sections) {
		std::regex pattern(it.first);
		if (std::regex_search(_line, pattern)) {
			_sectionKey = it.first;
			ret = true;
		}
	}
	return ret;
}

void nts::Parsing::delComment()
{
	std::size_t comment = _line.find('#');

	if (comment != std::string::npos) {
		_line.erase(comment);
	}
}

void nts::Parsing::parseLine()
{
	std::regex empty("^( |\t)*$");

	delComment();
	if (std::regex_search(_line, empty))
		return;
	if (!checkSection() && _sections.find(_sectionKey) != _sections.end()) {
		(this->*(_sections[_sectionKey]))();
	}
}

void nts::Parsing::components()
{
	std::regex pattern("^( |\t)*(\\w+)( |\t)+(\\w+)( |\t)*(\\((\\w)\\))*( |\t)*$");
	std::smatch groupes;

	if (std::regex_search(_line, groupes, pattern)) {
		if (_components.find(groupes[4].str()) != _components.end())
			throw nts::errorParsing("Multiple definition of ", groupes[4].str());
		std::string type = groupes[2].str();
		std::string value = groupes[7].str();
		if (type == "true")
			value = "1";
		if (type == "false")
			value = "0";
		if (_arguments.find(groupes[4].str()) != _arguments.end() &&
			(type == "input" || type == "clock"))
			value = _arguments[groupes[4].str()];

		nts::IComponent *component = create(type, value);

		_components.insert(
			std::pair<std::string, nts::IComponent *>(groupes[4].str(), component));
		if (type == "clock")
			_clocks[groupes[4].str()] = (nts::Clock *)component;
		if (type == "input")
			_inputs[groupes[4].str()] = (nts::Input *)component;
		if (type == "output")
			_outputs[groupes[4].str()] = (nts::Output *)component;
	} else {
		throw nts::errorParsing("Error with component at line: ", _line);
	}
}

void nts::Parsing::links()
{
	std::regex pattern("^( |\t*)(\\w+):(\\d+)( |\t)+(\\w+):(\\d+)( |\t*)$");
	std::smatch groupes;

	if (std::regex_search(_line, groupes, pattern)) {
		nts::Parsing::linkStruct actual = {
			groupes[2].str(),
			(size_t) stoi(groupes[3].str()),
			groupes[5].str(),
			(size_t) stoi(groupes[6].str())
		};
		_links.push_back(actual);
	} else {
		throw nts::errorParsing("Error with link at line: ", _line);
	}
}

void nts::Parsing::setLinks()
{
	for (auto &it: _links) {
		if (!ISINMAP(it.name1, _components) ||
			!ISINMAP(it.name2, _components))
			throw nts::errorParsing("Link name doesn't exist", "");

		nts::IComponent *c1 = _components.at(it.name1);
		nts::IComponent *c2 = _components.at(it.name2);

		if (ISINMAP(it.name1, _outputs) || ISINMAP(it.name2, _inputs)) {
			c1->setLink(it.pin1, *c2, it.pin2);
		} else {
			c2->setLink(it.pin2, *c1, it.pin1);
		}
	}
}

nts::IComponent *nts::Parsing::create(std::string &type, std::string &value)
{
	nts::IComponent *component = factory.create(type);

	if (component == nullptr)
		throw nts::errorParsing("Unknow type: ", type);

	if (value.empty() && type == "input")
		throw nts::errorParsing("Input  need value", "");
	if (!value.empty() && (type == "input" || type == "clock" || type == "true" ||
			type == "false")) {
		((nts::Input *)component)->setValue(value == "1" ? nts::TRUE : nts::FALSE);
	}
	return component->copy();
}