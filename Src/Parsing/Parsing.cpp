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
#include "Output.hpp"

static const std::string *AUTHORIZED_VALUE = new std::string("01");
static const std::vector <std::string> TYPES = {
	"input", "output", "clock", "true", "false", "2716", "4001", "4008",
	"4011", "4013", "4017", "4030", "4040", "4069", "4071", "4081",
	"4094", "4503", "4512", "4514",	"i4004", "mk4801"
};

nts::Parsing::Parsing(std::string const &FileName, int &ac, char **&av) : _FileName(
	FileName), _ac(ac), _av(av)
{
	ParseArgument();
	ParseFile();
}

void nts::Parsing::VerifEqualArgument(std::string &Arg)
{
	unsigned long int Equal = Arg.find('=');
	unsigned long int PosEqual = Arg.find_last_of('=');

	if (Equal == std::string::npos)
		throw nts::ErrorParsing("Argument need value : ", Arg);
	if (Equal != PosEqual || (Equal == std::string::npos && PosEqual == std::string::npos))
		throw nts::ErrorParsing("Multi equal is not allowed : ", Arg);
}

std::string nts::Parsing::StockNameArg(std::string &Arg)
{
	unsigned long int Equal = Arg.find('=');

	std::string Name = Arg.substr(0, Equal);
	return (Name);
}

std::string nts::Parsing::StockValueArg(std::string &Arg)
{
	unsigned long int Equal = Arg.find('=');

	std::string Value = Arg.substr(Equal + 1, Arg.size() - (Equal + 1));
	if (AUTHORIZED_VALUE->find(Value) == std::string::npos)
		throw nts::ErrorParsing("Value is 0 or 1 not ", Value);
	return (Value);
}

void nts::Parsing::ParseArgument()
{
	int i = 0;

	if (_ac == 2)
		return;
	for (int cpt = 2; cpt != _ac && _av[cpt]; cpt++) {
		std::string Arg(_av[cpt]);
		VerifEqualArgument(Arg);
		std::string NameArg = StockNameArg(Arg);
		std::string ValueArg = StockValueArg(Arg);
		_NameArg.push_back(NameArg);
		_ValueArg.push_back(ValueArg);
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

void nts::Parsing::DelSpaceAndTab(std::string &Line)
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
	if (_PosInFile == 2) {
		pos = Line.find_last_of(' ');
		while (pos + 1 == Line.size()) {
			Line.erase(pos, 1);
			pos = Line.find_last_of(' ');
		}
	}
}

void nts::Parsing::DelComment(std::string &Line)
{
	std::size_t PosComment = Line.find('#');

	if (!PosComment) {
		Line.erase(PosComment, (Line.size() - PosComment));
	}
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
		_LinkInFile = true;
		ret = -1;
	}
	return (ret);
}

void nts::Parsing::DefineType(std::string &Line)
{
	for (unsigned int i = 0; i != TYPES.size(); i++) {
		std::size_t PosType = Line.find(TYPES[i]);
		if (PosType == 0) {
			std::size_t SizeType = TYPES[i].size();
			Line.erase(PosType, SizeType);
			_Type = TYPES[i];
			return;
		}
	}
	throw nts::ErrorParsing("Chipset type is unknown : ", Line);
}

void nts::Parsing::DefineName(std::string &Line)
{
	DelSpaceAndTab(Line);
	if (Line.empty())
		throw nts::ErrorParsing("Error no name specified for the type : ",
			_Type);
	else {
		_Name = Line;
	}
}

void nts::Parsing::DefineValue(std::string &Line)
{
	unsigned long int FirstPos = Line.find('(');
	unsigned long int SecondPos = Line.find(')');
	unsigned long int CheckFirst = Line.find_last_of('(');
	unsigned long int CheckSecond = Line.find_last_of(')');

	if (FirstPos + 1 == SecondPos)
		throw nts::ErrorParsing("Variable need value : ", Line);
	if (CheckFirst != FirstPos || CheckSecond != SecondPos)
		throw nts::ErrorParsing("To many value : ", Line);
	if (FirstPos != std::string::npos && SecondPos != std::string::npos) {
		_Value = Line.substr(FirstPos + 1, 1);
		Line.erase(FirstPos, SecondPos);
	}
	if (_Value != "1" && _Value != "0" && !_Value.empty())
		throw nts::ErrorParsing("Value is 0 or 1 not ", _Value);
}

void nts::Parsing::setComponent()
{
	nts::IComponent *component = nullptr;
	try {
		 component = &create(_Type, _Value);
	} catch(nts::ErrorParsing &e) {
		throw nts::ErrorParsing(e.GetMessage(), e.GetIndication());
	}
	std::cout << _Name.data() << std::endl;
	if (_components.find(_Name) != _components.end()) {
		throw nts::ErrorParsing("Multiple definition of ", _Name);
	}
	_components.insert(std::pair<std::string, nts::IComponent *>(_Name, component));

	if (_Type == "clock")
		_clocks[_Name] = (nts::Clock *) component;
	if (_Type == "input")
		_inputs[_Name] = (nts::Input *) component;
	if (_Type == "output")
		_outputs[_Name] = (nts::Output *) component;
}

void nts::Parsing::ModifValueWithArg()
{
	for (size_t pos = 0; pos < _NameArg.size(); pos++) {
		if (_NameArg[pos] == _Name) {
			_Value = _ValueArg[pos];
			_NameArg.erase(_NameArg.begin() + pos);
			_ValueArg.erase(_ValueArg.begin() + pos);
		}
	}
}

void nts::Parsing::StockChipset(std::string &Line)
{
	DefineType(Line);
	DefineValue(Line);
	if (_Type == "output" || _Type == "false")
		_Value = "0";
	if (_Type == "true")
		_Value = "1";
	DefineName(Line);
	ModifValueWithArg();
	if (_Value.empty() && _Type == "input")
		throw ErrorParsing("Input name need value.", "");
	setComponent();
	_FileMap[_Name] = _Type;
}

void nts::Parsing::ChipsetsOrLinksIsNotInFile()
{
	if (!_ChipsetInFile)
		throw nts::ErrorParsing("Chipsets section not in file.", "");
	if (!_LinkInFile)
		throw nts::ErrorParsing("Links section not in file.", "");
}

void nts::Parsing::StockLinks(std::string &Line)
{
	unsigned long int PosSpace = Line.find(' ');
	unsigned long int PosTab = Line.find('\t');

	if (PosSpace == std::string::npos && PosTab == std::string::npos)
		throw ErrorParsing("Problem delimitation links : ", Line);

	unsigned long int PosSemicolons = Line.find(':');
	unsigned long int SecondPosSemicolons = Line.find_last_of(':');

	if (PosSemicolons == SecondPosSemicolons)
		throw ErrorParsing("No semicolon delimiter in the line : ",
			Line);

	std::string name = Line.substr(0, PosSemicolons);

	if (_components.find(name) == _components.end())
		throw ErrorParsing("Name in section link is unknown : ", name);
	PosSpace = Line.find(' ');
	std::string value = Line.substr(PosSemicolons + 1,
		(PosSpace - 1) - PosSemicolons);
	_NameLink.push_back(name);
	_ValueLink.push_back(value);
	PosSpace = Line.find_last_of(' ');
	name = Line.substr(PosSpace + 1, SecondPosSemicolons - 1 - PosSpace);
	value = Line.substr(SecondPosSemicolons + 1, Line.size());
	_NameLink.push_back(name);
	_ValueLink.push_back(value);
}

void nts::Parsing::ParseLine(std::string &Line)
{
	int ret = 0;

	DelComment(Line);
	DelSpaceAndTab(Line);
	if (Line.empty())
		return;
	ret = VerifLink(Line);
	if (_PosInFile == 2 && ret == 0)
		StockLinks(Line);
	ret = VerifChipset(Line);
	if (_PosInFile == 1 && ret == 0)
		StockChipset(Line);
}

void nts::Parsing::VerifEmptyArg()
{
	if (!_NameArg.empty())
		throw ErrorParsing("Error with the name of argument : ", "");
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
		/*		for (unsigned int i = 0; i != _ValueLink.size(); i++) {
					std::cout << "Name = " << _NameLink[i] << " value = " << _ValueLink[i] << std::endl;
					std::cout << _FileMap[_NameLink[i]] << std::endl;
				}*/
		VerifEmptyArg();
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
		{"output", new nts::Output()},
		{"clock", new nts::Clock()},
		{"true", new nts::Input()},
		{"false", new nts::Input()},
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

	for (auto &it : types) {
		if (it.first != type)
			delete it.second;
	}

	if (!value.empty() && (type == "input" || type == "clock"
		|| type == "true" || type == "false")) {
		((nts::Input *) component)->setValue(transformValue(value));
	}
	return *component;
}