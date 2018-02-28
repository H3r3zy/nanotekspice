/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include "Parsing.hpp"
#include "../../Include/IComponent.hpp"
#include "../../Include/Component/AndGate.hpp"

nts::Parsing::Parsing(std::string fileName, int ac, char **av) : _fileName(
	fileName), _ac(ac), _av(av)
{
	parseArgument();
	parseFile();
}

nts::Parsing::~Parsing()
{
}

void nts::Parsing::verifEqualArgument(std::string &arg)
{
	int equal = arg.find("=");
	int posEqual = arg.find_last_of("=");

	if (equal == -1)
		throw errorParsing("Argument need value : ", arg);
	if (equal != posEqual || (equal == -1 && posEqual == -1))
		throw errorParsing("Multi equal is not allowed : ", arg);
}

std::string nts::Parsing::stockNameArg(std::string &arg)
{
	int equal = arg.find("=");

	std::string name = arg.substr(0, equal);
	return (name);
}

std::string nts::Parsing::stockValueArg(std::string &arg)
{
	int equal = arg.find("=");

	std::string value = arg.substr(equal + 1, arg.size() - (equal + 1));
	if (value != "1" && value != "0")
		throw errorParsing("Value is 0 or 1 not ", value);
	return (value);
}

void nts::Parsing::parseArgument()
{
	int i = 0;

	if (_ac == 2)
		return;
	for (int cpt = 2; cpt != _ac; cpt++) {
		if (_av[cpt] == NULL)
			return;
		std::string arg(_av[cpt]);
		verifEqualArgument(arg);
		std::string nameArg = stockNameArg(arg);
		std::string valueArg = stockValueArg(arg);
		_nameArg.push_back(nameArg);
		_valueArg.push_back(valueArg);
		i++;
	}
}

std::map<std::string, nts::IComponent *> nts::Parsing::getMapInfoFile()
{
	return (_mapInfoFile);
}

std::map<std::string, nts::IComponent *> nts::Parsing::getMapInput()
{
	return (_mapInputFile);
}

std::map<std::string, nts::IComponent *> nts::Parsing::getMapOutput()
{
	return (_mapOutputFile);
}

std::map<std::string, nts::IComponent *> nts::Parsing::getMapClock()
{
	return (_mapClockFile);
}

void nts::Parsing::delSpaceAndTab(std::string &line)
{
	std::size_t pos = line.find("\t");
	while (pos != std::string::npos) {
		line.replace(pos, 1, " ");
		pos = line.find("\t", pos);
	}
	pos = line.find("  ");
	while (pos != std::string::npos) {
		line.replace(pos, 2, " ");
		pos = line.find("  ", pos);
	}
	pos = line.find(" ");
	while (pos == 0) {
		line.erase(0, 1);
		pos = line.find(" ");
	}
	if (_posInFile == 2) {
		pos = line.find_last_of(" ");
		while (pos + 1 == line.size()) {
			line.erase(pos, 1);
			pos = line.find_last_of(" ");
		}
	}
}

void nts::Parsing::delComment(std::string &line)
{
	std::size_t posComment = line.find("#");

	if (!posComment)
		line.erase(posComment, (line.size() - posComment));
}

int nts::Parsing::verifChipset(std::string line)
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

int nts::Parsing::verifLink(std::string line)
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
	std::vector <std::string> vectorType{"input", "output", "clock", "true",
		"false", "2716", "4001", "4008", "4011", "4013", "4017", "4030",
		"4040", "4069", "4071", "4081", "4094", "4503", "4512", "4514"
			"i4004", "mk4801"};

	for (unsigned int i = 0; i != vectorType.size(); i++) {
		std::size_t posType = line.find(vectorType[i]);
		if (posType == 0) {
			std::size_t sizeType = vectorType[i].size();
			line.erase(posType, sizeType);
			_type = vectorType[i];
			return;
		}
	}
	throw errorParsing("Chipset type is unknown : ", line);
}

int nts::Parsing::verifUniqueName(std::string line)
{
	for (unsigned int i = 0; i != _allName.size(); i++) {
		if (_allName[i] == line)
			return (-1);
	}
	return (0);
}

void nts::Parsing::defineName(std::string &line)
{
	delSpaceAndTab(line);
	if (line == "")
		throw errorParsing("Error no name specified for the type : ",
			_type);
	else {
		int ret = verifUniqueName(line);
		if (ret == -1)
			throw errorParsing("Multiple definition name : ", line);
		_name = line;
		_allName.push_back(line);
	}
}

void nts::Parsing::defineValue(std::string &line)
{
	int firstPos = line.find("(");
	int secondPos = line.find(")");
	int checkFirst = line.find_last_of("(");
	int checkSecond = line.find_last_of(")");

	if (firstPos + 1 == secondPos)
		throw errorParsing("Variable need value : ", line);
	if (checkFirst != firstPos || checkSecond != secondPos)
		throw errorParsing("To many value : ", line);
	if (firstPos != -1 && secondPos != -1) {
		_value = line.substr(firstPos + 1, 1);
		line.erase(firstPos, secondPos);
	}
	if (_value != "1" && _value != "0" && _value != "")
		throw errorParsing("Value is 0 or 1 not ", _value);
}

void nts::Parsing::setMapInfo()
{
	_mapInfoFile[_name] = new AndGate();

	if (_type == "input")
		_mapInputFile[_name] = _mapInfoFile[_name];
	else if (_type == "output")
		_mapOutputFile[_name] = _mapInfoFile[_name];
	else if (_type == "clock")
		_mapClockFile[_name] = _mapInfoFile[_name];
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

void nts::Parsing::stockChipset(std::string line)
{
	defineType(line);
	defineValue(line);
	if (_type == "output")
		_value = "0";
	defineName(line);
	modifValueWithArg();
	if (_value.empty() && _type == "input")
		throw errorParsing("Input name need value.", "");
	setMapInfo();
	_fileMap[_name] = _type;
}

void nts::Parsing::chipsetsOrLinksIsNotInFile()
{
	if (!_chipsetInFile)
		throw errorParsing("Chipsets section not in file.", "");
	if (!_linkInFile)
		throw errorParsing("Links section not in file.", "");
}

int nts::Parsing::verifNameExiste(std::string name)
{
	for (unsigned int i = 0; i != _allName.size(); i++) {
		if (_allName[i] == name)
			return (0);
	}
	return (1);
}

void nts::Parsing::stockLinks(std::string &line)
{
	int posSpace = line.find(" ");
	int posTab = line.find("\t");
	int posSemicolons = line.find(":");
	int secondPosSemicolons = line.find_last_of(":");

	if (posSpace == -1 && posTab == -1) {
		throw errorParsing("Problem delimitation links : ", line);
	}
	if (posSemicolons == secondPosSemicolons)
		throw errorParsing("No semicolon delimiter in the line : ",
			line);
	std::string name = line.substr(0, posSemicolons);
	//std::cout << "Name = " << name << std::endl;
	if (verifNameExiste(name) == 1)
		throw errorParsing("Name in section link is unknow : ", name);
	posSpace = line.find(" ");
	std::string value = line.substr(posSemicolons + 1,
		(posSpace - 1) - posSemicolons);
	_nameLink.push_back(name);
	_valueLink.push_back(value);
	posSpace = line.find_last_of(" ");
	name = line.substr(posSpace + 1, secondPosSemicolons - 1 - posSpace);
	value = line.substr(secondPosSemicolons + 1, line.size());
	_nameLink.push_back(name);
	_valueLink.push_back(value);
}

int nts::Parsing::isComponent(std::string line)
{
	if (line != "input" && line != "output" && line != "clock" &&
		line != "true" && line != "false")
		return (0);
	return (1);
}

void nts::Parsing::parseLine(std::string line)
{
	int ret = 0;

	delComment(line);
	delSpaceAndTab(line);
	if (line.empty())
		return;
	ret = verifLink(line);
	if (_posInFile == 2 && ret == 0)
		stockLinks(line);
	ret = verifChipset(line);
	if (_posInFile == 1 && ret == 0)
		stockChipset(line);
}

void nts::Parsing::verifEmptyArg()
{
	if (!_nameArg.empty())
		throw errorParsing("Error with the name of argument : ",
			_nameArg[0]);
}

void nts::Parsing::parseFile()
{
	std::ifstream file(_fileName.c_str());

	if (file) {
		std::string line;
		while (getline(file, line)) {
			parseLine(line);
			_type = "";
			_name = "";
			_value = "";
		}
		/*int cpt1 = 0;
		int cpt2 = 1;
		std::cout << _NameLink.size() << std::endl;
		for (unsigned int i = 0; i != _NameLink.size(); i = i + 2) {
			_MapInfoFile
			nts::IComponent *Componnent1;
			nts::IComponent *Componnent2;

			if (_FileMap[_NameLink[cpt1]] == "input" && IsComponent(_FileMap[_NameLink[cpt2]]) == 0) {

				_NameLink[cpt1]->setLink(atoi(_ValueLink[0].c_str()), _NameLink[1], atoi(_ValueLink[1].c_str()));
				std::cout << _ValueLink[cpt1]  << "   " << _NameLink[cpt2] << "    " << _ValueLink[cpt2] << std::endl;
			}
			if (IsComponent(_FileMap[_NameLink[cpt1]]) == 0 && _FileMap[_NameLink[cpt2]] == "input") {
				std::cout << _ValueLink[cpt1]  << "   " << _NameLink[cpt2] << "    " << _ValueLink[cpt2] << std::endl;
			}
			if (IsComponent(_FileMap[_NameLink[cpt1]]) == 0 && _FileMap[_NameLink[cpt2]] == "output") {
				std::cout << _ValueLink[cpt1]  << "   " << _NameLink[cpt2] << "    " << _ValueLink[cpt2] << std::endl;
			}
			if (_FileMap[_NameLink[cpt1]] == "output" && IsComponent(_FileMap[_NameLink[cpt2]]) == 0) {
				//nts::IComponent::setLink(atoi(_ValueLink[0].data()), _NameLink[1], atoi(_ValueLink[1].data()));
				std::cout << _ValueLink[cpt1]  << "   " << _NameLink[cpt2] << "    " << _ValueLink[cpt2] << std::endl;
			}
			cpt1 = cpt1 + 2;
			cpt2 = cpt2 + 2;
		}*/
		verifEmptyArg();
		chipsetsOrLinksIsNotInFile();
	} else {
		throw errorParsing("Bad file given as parameter : ", _fileName);
	}
}