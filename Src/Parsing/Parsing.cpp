/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include <unordered_map>
#include <Parsing/Parsing.hpp>
#include "AbstractComponent.hpp"
#include "Parsing.hpp"
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
#include "Output.hpp"

static const std::string AUTHORIZED_VALUE("01");
static const std::vector<std::string> TYPES({
	"input", "output", "clock", "true", "false", "2716", "4001", "4008",
	"4011", "4013", "4017", "4030", "4040", "4069", "4071", "4081",
	"4094", "4503", "4512", "4514",	"i4004", "mk4801"
});

nts::Parsing::Parsing(std::string &fileName, int &ac, char **&av) : _fileName(
	fileName), _ac(ac), _av(av)
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
	//factory.add("4013", new nts::CD4011B());
	//factory.add("4017", new nts::CD4011B());
	factory.add("4030", new nts::CD4030C());
	//factory.add("4040", new nts::CD4011B());
	factory.add("4069", new nts::CD4069UBC());
	factory.add("4071", new nts::HEF4071B());
	factory.add("4081", new nts::HCF4081B());
//	factory.add("4094", new nts::4094());
//	factory.add("4503", new nts::CD4011B());
	factory.add("4512", new nts::CD4512B());
	factory.add("4514", new nts::CD4514BC());
	//factory.add("i4004", new nts::CD4011B());
	//factory.add("mk4801", new nts::CD4011B());
	parseArgument();
	parseFile();
}

void nts::Parsing::verifEqualArgument(std::string &arg)
{
	unsigned long int equal = arg.find('=');
	unsigned long int posEqual = arg.find_last_of('=');

	if (equal == std::string::npos)
		throw nts::errorParsing("Argument need value : ", arg);
	if (equal != posEqual || (equal == std::string::npos && posEqual == std::string::npos))
		throw nts::errorParsing("Multi equal is not allowed : ", arg);
}

std::string nts::Parsing::stockNameArg(std::string &arg)
{
	long unsigned int equal = arg.find('=');

	std::string name = arg.substr(0, equal);
	return (name);
}

std::string nts::Parsing::stockValueArg(std::string &arg)
{
	long unsigned int equal = arg.find('=');

	std::string value = arg.substr(equal + 1, arg.size() - (equal + 1));
	if (AUTHORIZED_VALUE.find(value) == std::string::npos)
		throw nts::errorParsing("Value is 0 or 1 not ", value);
	return (value);
}

void nts::Parsing::parseArgument()
{
	int i = 0;

	if (_ac == 2)
		return;
	for (int cpt = 2; cpt != _ac && _av[cpt]; cpt++) {
		std::string arg(_av[cpt]);
		verifEqualArgument(arg);
		std::string nameArg = stockNameArg(arg);
		std::string valueArg = stockValueArg(arg);
		_nameArg.push_back(nameArg);
		_valueArg.push_back(valueArg);
		i++;
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

std::map<std::string, nts::Clock *>& nts::Parsing::getClocks()
{
	return _clocks;
}

void nts::Parsing::delSpaceAndTab(std::string &line)
{
	if (line.empty())
		return;
	std::size_t pos = line.find('\t');
	while (pos != std::string::npos) {
		line.replace(pos, 1, " ");
		pos = line.find('\t', pos);
	}
	pos = line.find("  ");
	while (pos != std::string::npos) {
		line.replace(pos, 2, " ");
		pos = line.find("  ", pos);
	}
	pos = line.find(' ');
	while (pos == 0) {
		line.erase(0, 1);
		pos = line.find(' ');
	}
	if (_posInFile == 2) {
		pos = line.find_last_of(' ');
		while (pos + 1 == line.size()) {
			line.erase(pos, 1);
			pos = line.find_last_of(' ');
		}
	}
}

void nts::Parsing::delComment(std::string &line)
{
	std::size_t posComment = line.find('#');

	if (!posComment)
		line.erase(posComment, (line.size() - posComment));
}

int nts::Parsing::verifChipset(std::string &line)
{
	int ret = 0;
	std::size_t chipsetIsOk = line.find(".chipsets:");

	if (!chipsetIsOk) {
		_posInFile = 1;
		_chipsetInFile = true;
		ret = -1;
	}
	return (ret);
}

int nts::Parsing::verifLink(std::string &line)
{
	int ret = 0;
	std::size_t linksIsOk = line.find(".links:");

	if (!linksIsOk) {
		_posInFile = 2;
		_linkInFile = true;
		ret = -1;
	}
	return (ret);
}

void nts::Parsing::defineType(std::string &line)
{
	for (unsigned int i = 0; i != TYPES.size(); i++) {
		std::size_t posType = line.find(TYPES[i]);
		if (posType == 0) {
			std::size_t sizeType = TYPES[i].size();
			line.erase(posType, sizeType);
			_type = TYPES[i];
			return;
		}
	}
	throw nts::errorParsing("Chipset type is unknown : ", line);
}

void nts::Parsing::defineName(std::string &line)
{
	delSpaceAndTab(line);
	if (line.empty())
		throw nts::errorParsing("Error no name specified for the type : ",
			_type);
	else {
		_name = line;
	}
}

void nts::Parsing::defineValue(std::string &line)
{
	unsigned long int firstPos = line.find('(');
	unsigned long int secondPos = line.find(')');
	unsigned long int checkFirst = line.find_last_of('(');
	unsigned long int checkSecond = line.find_last_of(')');

	if (firstPos + 1 == secondPos)
		throw nts::errorParsing("Variable need value : ", line);
	if (checkFirst != firstPos || checkSecond != secondPos)
		throw nts::errorParsing("To many value : ", line);
	if (firstPos != std::string::npos && secondPos != std::string::npos) {
		_value = line.substr(firstPos + 1, 1);
		line.erase(firstPos, secondPos);
	}
	if (AUTHORIZED_VALUE.find(_value) == std::string::npos && !_value.empty())
		throw nts::errorParsing("Value is 0 or 1 not ", _value);
}

void nts::Parsing::setComponent()
{
	nts::IComponent *component = nullptr;
	try {
		 component = create(_type, _value);
	} catch(nts::errorParsing &e) {
		throw nts::errorParsing(e.getMessage(), e.getIndication());
	}
	if (_components.find(_name) != _components.end()) {
		throw nts::errorParsing("Multiple definition of ", _name);
	}
	_components.insert(std::pair<std::string, nts::IComponent *>(_name, component));

	if (_type == "clock")
		_clocks[_name] = (nts::Clock *) component;
	if (_type == "input")
		_inputs[_name] = (nts::Input *) component;
	if (_type == "output")
		_outputs[_name] = (nts::Output *) component;
}

void nts::Parsing::modifValueWithArg()
{
	for (size_t pos = 0; pos < _nameArg.size(); pos++) {
		if (_nameArg[pos] == _name) {
			_value = _valueArg[pos];
			_nameArg.erase(_nameArg.begin() + pos);
			_valueArg.erase(_valueArg.begin() + pos);
		}
	}
}

void nts::Parsing::stockChipset(std::string &line)
{
	defineType(line);
	defineValue(line);
	if (_type == "output" || _type == "false")
		_value = "0";
	if (_type == "true")
		_value = "1";
	defineName(line);
	modifValueWithArg();
	if (_value.empty() && _type == "input")
		throw nts::errorParsing("Input name need value.", "");
	setComponent();
	_fileMap[_name] = _type;
}

void nts::Parsing::chipsetsOrLinksIsNotInFile()
{
	if (!_chipsetInFile)
		throw nts::errorParsing("Chipsets section not in file.", "");
	if (!_linkInFile)
		throw nts::errorParsing("Links section not in file.", "");
}

void nts::Parsing::stockLinks(std::string &line)
{
	unsigned long int posSpace = line.find(' ');
	unsigned long int posTab = line.find('\t');
	unsigned long int posSemicolons = line.find(':');
	unsigned long int secondPosSemicolons = line.find_last_of(':');

	if (posSpace == std::string::npos && posTab == std::string::npos) {
		throw nts::errorParsing("Problem delimitation links : ", line);
	}
	if (posSemicolons == secondPosSemicolons)
		throw nts::errorParsing("No semicolon delimiter in the line : ",
			line);
	std::string name = line.substr(0, posSemicolons);
	posSpace = line.find(' ');
	std::string value = line.substr(posSemicolons + 1,
		(posSpace - 1) - posSemicolons);
	_nameLink.push_back(name);
	_valueLink.push_back(value);
	posSpace = line.find_last_of(' ');
	name = line.substr(posSpace + 1, secondPosSemicolons - 1 - posSpace);
	value = line.substr(secondPosSemicolons + 1, line.size());
	_nameLink.push_back(name);
	_valueLink.push_back(value);
}

void nts::Parsing::parseLine(std::string &line)
{
	int ret = 0;

	delComment(line);
	delSpaceAndTab(line);
	if (line.empty()) {
		return;
	}
	ret = verifLink(line);
	if (_posInFile == 2 && ret == 0) {
		stockLinks(line);
	}
	ret = verifChipset(line);
	if (_posInFile == 1 && ret == 0) {
		stockChipset(line);
	}
}

void nts::Parsing::verifEmptyArg()
{
	if (!_nameArg.empty())
		throw nts::errorParsing("Error with the name of argument : ", "");
}

void nts::Parsing::parseFile()
{
	std::ifstream file(_fileName.c_str());
	std::cout << "in" << std::endl;

	if (file) {
		std::string line;
		while (getline(file, line)) {
			parseLine(line);
			_type = "";
			_name = "";
			_value = "";
		}
		for (unsigned int i = 0; i != _nameLink.size(); i = i + 2) {
			std::string name1 = _nameLink[i];
			std::string name2 = _nameLink[i + 1];
			nts::IComponent *component1 = _components.at(name1);
			nts::IComponent *component2 = _components.at(name2);

			if (!ISINMAP(name1, _components) || !ISINMAP(name2, _components)) {
				throw nts::errorParsing("link name is not good", "");
			}
			if (ISINMAP(name1, _outputs) || ISINMAP(name2, _inputs)) {
				component1->setLink((unsigned int) atoi(_valueLink[i].c_str()), *component2, (unsigned int) atoi(_valueLink[i + 1].c_str()));
			} else {
				component2->setLink((unsigned int) atoi(_valueLink[i + 1].c_str()), *component1, (unsigned int) atoi(_valueLink[i].c_str()));
			}
		}
		verifEmptyArg();
		chipsetsOrLinksIsNotInFile();
	} else {
		throw nts::errorParsing("Bad file given as parameter : ", _fileName);
	}
}

nts::Tristate nts::Parsing::transformValue(std::string const &value)
{
	nts::Tristate tri = nts::UNDEFINED;

	if (value == "1") {
		tri = nts::TRUE;
	} else if (value == "0") {
		tri = nts::FALSE;
	}
	return tri;
}

nts::IComponent *nts::Parsing::create(std::string const &type,
	std::string const &value
)
{
	nts::IComponent *component = factory.create(type);

	if (component == nullptr)
		throw nts::errorParsing("Unknow type: ", type);


	if (!value.empty() && (type == "input" || type == "clock"
		|| type == "true" || type == "false")) {
		((nts::Input *) component)->setValue(transformValue(value));
	}
	return component->copy();
}