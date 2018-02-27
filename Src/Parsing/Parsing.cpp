/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include "Parsing.hpp"
#include "../../Include/IComponent.hpp"

nts::Parsing::Parsing(std::string FileName, int ac, char **av) : _FileName(
	FileName), _ac(ac), _av(av)
{
	ParseArgument();
	ParseFile();
}

nts::Parsing::~Parsing()
{
}

void nts::Parsing::VerifEqualArgument(std::string &Arg)
{
	int Equal = Arg.find("=");
	int PosEqual = Arg.find_last_of("=");

	if (Equal == -1)
		throw ErrorParsing("Argument need value : ", Arg);
	if (Equal != PosEqual || (Equal == -1 && PosEqual == -1))
		throw ErrorParsing("Multi equal is not allowed : ", Arg);
}

std::string nts::Parsing::StockNameArg(std::string &Arg)
{
	int Equal = Arg.find("=");

	std::string Name = Arg.substr(0, Equal);
	return (Name);
}

std::string nts::Parsing::StockValueArg(std::string &Arg)
{
	int Equal = Arg.find("=");

	std::string Value = Arg.substr(Equal + 1, Arg.size() - (Equal + 1));
	if (Value != "1" && Value != "0")
		throw ErrorParsing("Value is 0 or 1 not ", Value);
	return (Value);
}

void nts::Parsing::ParseArgument()
{
	int i = 0;

	if (_ac == 2)
		return;
	for (int cpt = 2; cpt != _ac; cpt++) {
		if (_av[cpt] == NULL)
			return;
		std::string Arg(_av[cpt]);
		VerifEqualArgument(Arg);
		std::string NameArg = StockNameArg(Arg);
		std::string ValueArg = StockValueArg(Arg);
		_NameArg.push_back(NameArg);
		_ValueArg.push_back(ValueArg);
		i++;
	}
}

/*std::map<std::string *, nts::IComponent> nts::Parsing::GetMapInfoFile()
{
	return (_MapInfoFile);
}*/

void nts::Parsing::DelSpaceAndTab(std::string &Line)
{
	std::size_t pos = Line.find("\t");
	while (pos != std::string::npos) {
		Line.replace(pos, 1, " ");
		pos = Line.find("\t", pos);
	}
	pos = Line.find("  ");
	while (pos != std::string::npos) {
		Line.replace(pos, 2, " ");
		pos = Line.find("  ", pos);
	}
	pos = Line.find(" ");
	while (pos == 0) {
		Line.erase(0, 1);
		pos = Line.find(" ");
	}
	if (_PosInFile == 2) {
		pos = Line.find_last_of(" ");
		while (pos + 1 == Line.size()) {
			Line.erase(pos, 1);
			pos = Line.find_last_of(" ");
		}
	}
}

void nts::Parsing::DelComment(std::string &Line)
{
	std::size_t PosComment = Line.find("#");

	if (!PosComment) {
		Line.erase(PosComment, (Line.size() - PosComment));
	}
}

int nts::Parsing::VerifChipset(std::string Line)
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

int nts::Parsing::VerifLink(std::string Line)
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
	std::vector <std::string> VectorType{"input", "output", "clock", "true",
		"false", "2716", "4001", "4008", "4011", "4013", "4017", "4030",
		"4040", "4069", "4071", "4081", "4094", "4503", "4512", "4514"
			"i4004", "mk4801"};

	for (unsigned int i = 0; i != VectorType.size(); i++) {
		std::size_t PosType = Line.find(VectorType[i]);
		if (PosType == 0) {
			std::size_t SizeType = VectorType[i].size();
			Line.erase(PosType, SizeType);
			_Type = VectorType[i];
			return;
		}
	}
	throw ErrorParsing("Chipset type is unknown : ", Line);
}

int nts::Parsing::VerifUniqueName(std::string Line)
{
	for (unsigned int i = 0; i != _AllName.size(); i++) {
		if (_AllName[i] == Line)
			return (-1);
	}
	return (0);
}

void nts::Parsing::DefineName(std::string &Line)
{
	DelSpaceAndTab(Line);
	if (Line == "")
		throw ErrorParsing("Error no name specified for the type : ",
			_Type);
	else {
		int ret = VerifUniqueName(Line);
		if (ret == -1)
			throw ErrorParsing("Multiple definition name : ", Line);
		_Name = Line;
		_AllName.push_back(Line);
	}
}

void nts::Parsing::DefineValue(std::string &Line)
{
	int FirstPos = Line.find("(");
	int SecondPos = Line.find(")");
	int CheckFirst = Line.find_last_of("(");
	int CheckSecond = Line.find_last_of(")");

	if (FirstPos + 1 == SecondPos)
		throw ErrorParsing("Variable need value : ", Line);
	if (CheckFirst != FirstPos || CheckSecond != SecondPos)
		throw ErrorParsing("To many value : ", Line);
	if (FirstPos != -1 && SecondPos != -1) {
		_Value = Line.substr(FirstPos + 1, 1);
		Line.erase(FirstPos, SecondPos);
	}
	if (_Value != "1" && _Value != "0" && _Value != "")
		throw ErrorParsing("Value is 0 or 1 not ", _Value);
}

void nts::Parsing::SetMapInfo()
{
	//_MapInfoFile[_Name] = nts::IComponent::create(_Type, _Value);
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

void nts::Parsing::StockChipset(std::string Line)
{
	DefineType(Line);
	DefineValue(Line);
	if (_Type == "output")
		_Value = "0";
	DefineName(Line);
	ModifValueWithArg();
	if (_Value.empty() && _Type == "input")
		throw ErrorParsing("Input name need value.", "");
	SetMapInfo();
	_FileMap[_Name] = _Type;
}

void nts::Parsing::ChipsetsOrLinksIsNotInFile()
{
	if (!_ChipsetInFile)
		throw ErrorParsing("Chipsets section not in file.", "");
	if (!_LinkInFile)
		throw ErrorParsing("Links section not in file.", "");
}

int nts::Parsing::VerifNameExiste(std::string name)
{
	for (unsigned int i = 0; i != _AllName.size(); i++) {
		if (_AllName[i] == name)
			return (0);
	}
	return (1);
}

void nts::Parsing::StockLinks(std::string &Line)
{
	int PosSpace = Line.find(" ");
	int PosTab = Line.find("\t");

	if (PosSpace == -1 && PosTab == -1)
		throw ErrorParsing("Problem delimitation links : ", Line);

	int PosSemicolons = Line.find(":");
	int SecondPosSemicolons = Line.find_last_of(":");

	if (PosSemicolons == SecondPosSemicolons)
		throw ErrorParsing("No semicolon delimiter in the line : ",
			Line);

	std::string name = Line.substr(0, PosSemicolons);
	if (VerifNameExiste(name) == 1)
		throw ErrorParsing("Name in section link is unknow : ", name);
	PosSpace = Line.find(" ");
	std::string value = Line.substr(PosSemicolons + 1,
		(PosSpace - 1) - PosSemicolons);
	_NameLink.push_back(name);
	_ValueLink.push_back(value);
	PosSpace = Line.find_last_of(" ");
	name = Line.substr(PosSpace + 1, SecondPosSemicolons - 1 - PosSpace);
	value = Line.substr(SecondPosSemicolons + 1, Line.size());
	_NameLink.push_back(name);
	_ValueLink.push_back(value);
}

void nts::Parsing::ParseLine(std::string Line)
{
	int ret = 0;

	DelComment(Line);
	DelSpaceAndTab(Line);
	if (Line == "")
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
	if (_NameArg.size() != 0)
		throw ErrorParsing("Error with the name of argument : ",
			_NameArg[0]);
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
		throw ErrorParsing("Bad file given as parameter : ", _FileName);
	}
}