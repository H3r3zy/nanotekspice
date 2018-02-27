/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/
#ifndef CPP_NANOTEKSPICE_PARSING_HPP
#define CPP_NANOTEKSPICE_PARSING_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include "ErrorParsing.hpp"

namespace nts {
	class Parsing {
	public:
		Parsing(std::string FileName, int ac, char **av);
		~Parsing();
		std::string GetNameFile();
		//std::map<std::string *, nts::IComponent> GetMapInfoFile();
	private:
		void ParseFile(void);
		void ParseArgument(void);
		void ParseLine(std::string Line);
		void StockChipset(std::string Line);
		void StockLinks(std::string &Line);
		void DelComment(std::string &Line);
		void DelSpaceAndTab(std::string &Line);
		void DefineName(std::string &Line);
		void DefineType(std::string &Line);
		void DefineValue(std::string &Line);
		void ChipsetsOrLinksIsNotInFile();
		int VerifLink(std::string Line);
		int VerifChipset(std::string Line);
		int VerifUniqueName(std::string Line);
		void ModifValueWithArg(void);
		void VerifEmptyArg(void);
		void VerifEqualArgument(std::string &Arg);
		std::string StockNameArg(std::string &Arg);
		std::string StockValueArg(std::string &Arg);
		int VerifNameExiste(std::string);
		std::vector<std::string> _AllName;
		//std::map<std::string *, nts::IComponent> GetMapInfoFile();
		//std::map<std::string, std::string> Pin;
		void SetMapInfo(void);
		std::vector<std::string> _NameArg;
		std::vector<std::string> _ValueArg;
		std::map<std::string, std::string> _FileMap;
		std::string _FileName;
		std::string _Type;
		std::string _Name;
		std::string _Value;
		std::vector<std::string> _NameLink;
		std::vector<std::string> _ValueLink;
		bool _ChipsetInFile;
		bool _LinkInFile;
		//std::map<std::string *, nts::IComponent> _MapInfoFile;
		short _PosInFile;
		int _ac;
		char **_av;

	};
}
#endif //CPP_NANOTEKSPICE_PARSING_HPP
