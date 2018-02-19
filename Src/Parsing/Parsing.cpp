/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include <unordered_map>
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

nts::Parsing::Parsing(std::string const &FileName) : _FileName(
	FileName)
{
	ParseArgument();
	ParseFile();
}

nts::Parsing::~Parsing()
{
}

void nts::Parsing::ParseArgument()
{
	//for (unsigned int cpt = 1; cpt != _ac; cpt++) {
	//}
}

std::map<std::string, nts::IComponent *> nts::Parsing::GetMapInfoFile() const
{
	return (_MapInfoFile);
}

std::string &nts::Parsing::DelSpaceAndTab(std::string &Line)
{
	std::size_t pos = Line.find('\t');
	while (pos != std::string::npos) {
		Line.replace(pos, 1, " ");
		pos = Line.find('\t', pos);
	}
	pos = Line.find("  ");
	while (pos != std::string::npos) {
		Line.replace(pos, 2, " ");
		pos = Line.find("  ", pos);
	}
	pos = Line.find(' ');
	while (pos == 0) {
		Line.erase(0, 1);
		pos = Line.find(' ');
	}
	return (Line);
}

std::string &nts::Parsing::DelComment(std::string &Line)
{
	std::size_t PosComment = Line.find('#');

	if (!PosComment) {
		Line.erase(PosComment, (Line.size() - PosComment));
	}
	return (Line);
}

int nts::Parsing::VerifChipset(std::string &Line)
{
	int ret = 0;
	std::size_t ChipsetIsOk = Line.find(".chipsets:");

	if (!ChipsetIsOk) {
		_PosInFile = 1;
		_ChipsetInFile = true;
		ret = -1;
	}
	return (ret);
}

int nts::Parsing::VerifLink(std::string &Line)
{
	int ret = 0;
	std::size_t LinksIsOk = Line.find(".links:");

	if (!LinksIsOk) {
		_PosInFile = 2;
		_ChipsetInFile = true;
		ret = -1;
	}
	return (ret);
}

std::string &nts::Parsing::DefineType(std::string &Line)
{
	std::vector <std::string> VectorType{"input", "output", "clock", "true",
		"false", "2716", "4001", "4008", "4011", "4013", "4017", "4030",
		"4040", "4069", "4071", "4081", "4094", "4503", "4512", "4514",
			"i4004", "mk4801"};

	for (unsigned int i = 0; i != VectorType.size(); i++) {
		std::size_t PosType = Line.find(VectorType[i]);
		if (PosType == 0) {
			std::size_t SizeType = VectorType[i].size();
			Line.erase(PosType, SizeType);
			_Type = VectorType[i];
			return (Line);
		}
	}
	throw nts::ErrorParsing("Chipset type is unknown : ", Line);
}

int nts::Parsing::VerifUniqueName(std::string &Line)
{
	for (unsigned int i = 0; i != _AllName.size(); i++) {
		if (_AllName[i] == Line)
			return (-1);
	}
	return (0);
}

void nts::Parsing::DefineName(std::string &Line)
{
	std::string Name = DelSpaceAndTab(Line);
	if (Name.empty())
		throw nts::ErrorParsing("Error no name specified for the type : ",
			_Type);
	else {
		//int ret = VerifUniqueName(Name);
		/*if (ret == -1)
			throw nts::ErrorParsing("Multiple definition of name : ",
				Line);*/
		_Name = Line;
		//_AllName.push_back(Line);
	}
}

std::string &nts::Parsing::DefineValue(std::string &Line)
{
	int FirstPos = Line.find("(");
	int SecondPos = Line.find(")");
	int check = Line.find_last_of("(");

	if (check != FirstPos)
		throw nts::ErrorParsing("To many value :", Line);
	if (FirstPos != -1 && SecondPos != -1) {
		_Value = Line.substr(FirstPos + 1, 1);
		Line.erase(FirstPos, SecondPos);
	}
	return (Line);
}

void nts::Parsing::SetMapInfo()
{
	nts::IComponent *component = nullptr;
	try {
		 component = &create(_Type, _Value);

	} catch(nts::ErrorParsing &e) {
		throw nts::ErrorParsing(e.GetMessage(), e.GetIndication());
	}
	if (_MapInfoFile.find(_Name) != _MapInfoFile.end()) {
		throw nts::ErrorParsing("Multiple definition of ", _Name);
	}
	_MapInfoFile.insert(std::pair<std::string, nts::IComponent *>(_Name, component));
}

void nts::Parsing::StockChipset(std::string &Line)
{
	DefineType(Line);
	DefineValue(Line);
	if (_Type == "output")
		_Value = "0";
	DefineName(Line);
	SetMapInfo();
}

void nts::Parsing::ChipsetsOrLinksIsNotInFile()
{
	if (!_ChipsetInFile)
		throw nts::ErrorParsing("Chipsets section not in file.", "");
	if (!_LinkInFile)
		throw nts::ErrorParsing("Links section not in file.", "");
}

void nts::Parsing::ParseLine(std::string &Line)
{
	int ret = 0;

	DelComment(Line);
	Line = DelSpaceAndTab(Line);
	if (Line.empty())
		return;
	ret = VerifLink(Line);
	/*if (_PosInFile == 2 && ret == 0)
		abort();*/
	ret = VerifChipset(Line);
	if (_PosInFile == 1 && ret == 0)
		StockChipset(Line);
}


void nts::Parsing::ParseFile()
{
	std::ifstream File(_FileName.c_str());

	if (File) {
		std::string Line;
		while (getline(File, Line)) {
			ParseLine(Line);
			_Type = "";
			_Name = "";
			_Value = "";
		}
		ChipsetsOrLinksIsNotInFile();
	} else {
		throw nts::ErrorParsing("Bad file given as parameter : ", _FileName);
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

nts::IComponent &nts::Parsing::create(std::string const &type,
	std::string const &value
)
{
	std::unordered_map<std::string, nts::IComponent *> types = {
		{"input", new nts::Input()},
		//{"output", },
		{"clock", new nts::Clock()},
		//{"true",},
		//"false",
		//"2716",
		{"4001", new nts::HEF4001B()},
		{"4008", new nts::CD4008BMS()},
		{"4011", new nts::CD4011B()},
		//{"4013", new nts::},
		//{"4017", },
		{"4030", new nts::CD4030C()},
		//"4040",
		{"4069", new nts::CD4069UBC()},
		{"4071", new nts::HEF4071B()},
		{"4081", new nts::HCF4081B()},
		//"4094",
		//"4503",
		{"4512", new nts::CD4512B()},
		{"4514", new nts::CD4514BC()},
		//"i4004",
		//{"mk4801", }
	};

	if (types.find(type) == types.end())
		throw nts::ErrorParsing("Unknow type: ", type);

	nts::IComponent *component = types[type];

	for (auto it = types.begin(); it != types.end(); ++it) {
		if (it->first != type)
			delete it->second;
	}

	if (!value.empty() && (type == "input" || type == "clock")) {
		((nts::Input *) component)->setValue(transformValue(value));
	}
	return *component;
}