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
#include "IComponent.hpp"

namespace nts {
	class Parsing {
	public:
		Parsing(std::string const &FileName);
		~Parsing();
		void ParseFile();
		void ParseLine(std::string &Line);
		int VerifChipset(std::string &Line);
		int VerifLink(std::string &Line);
		void StockChipset(std::string &Line);
		void DefineName(std::string &Line);
		void ChipsetsOrLinksIsNotInFile();
		int VerifUniqueName(std::string &Line);
		void SetMapInfo();
		std::map<std::string, nts::IComponent *> GetMapInfoFile() const;
		//std::map<std::string, std::string> Pin;
		//std::string &GetNameFile();
		std::string &DelComment(std::string &);
		std::string &DefineType(std::string &Line);
		std::string &DefineValue(std::string &Line);
		std::string &DelSpaceAndTab(std::string &Line);
		void ParseArgument();

	private:
		std::vector<std::string> _AllName;
		std::string _FileName;
		std::string _Type;
		std::string _Name;
		std::string _Value;
		bool _ChipsetInFile = false;
		bool _LinkInFile = false;
		std::map<std::string, nts::IComponent *> _MapInfoFile;
		short _PosInFile;

		nts::IComponent &create(std::string const &, std::string const &);
		nts::Tristate transformValue(std::string const &);
	};
}

#endif //CPP_NANOTEKSPICE_PARSING_HPP
