/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include "Parsing.hpp"
#include "../../Include/IComponent.hpp"

nts::Parsing::Parsing(std::string FileName) : _FileName(
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
			return ;
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

/*void nts::Parsing::SetMapInfo()
{
	//_MapInfoFile[_Name] = nts::IComponent::create(_Type, _Value);
}*/

void nts::Parsing::StockChipset(std::string Line)
{
	DefineType(Line);
	DefineValue(Line);
	if (_Type == "output")
		_Value = "0";
	DefineName(Line);
	//SetMapInfo();
}

void nts::Parsing::ChipsetsOrLinksIsNotInFile()
{
	if (!_ChipsetInFile)
		throw ErrorParsing("Chipsets section not in file.", "");
	if (!_LinkInFile)
		throw ErrorParsing("Links section not in file.", "");
}

void nts::Parsing::ParseLine(std::string Line)
{
	int ret = 0;

	DelComment(Line);
	DelSpaceAndTab(Line);
	if (Line == "")
		return;
	ret = VerifLink(Line);
	//if (_PosInFile == 2 && ret == 0)
		//StockLinks(Line);
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
		throw ErrorParsing("Bad file given as parameter : ", _FileName);
	}
}