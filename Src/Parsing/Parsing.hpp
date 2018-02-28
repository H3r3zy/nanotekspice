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
#include "Input.hpp"
#include "Clock.hpp"
#include "ErrorParsing.hpp"
#include "IComponent.hpp"

namespace nts {
	class Parsing {
	public:
		Parsing(std::string const &FileName);
		~Parsing();

		//getteur
		std::map<std::string, nts::IComponent *> GetMapInfoFile() const;
		std::string const &GetNameFile() const;

		//parsing
		void ParseFile();
		void ParseArgument();
		void ParseLine(std::string &Line);
		void StockChipset(std::string &Line);
		void StockLinks(std::string &Line);
		void SetMapInfo();
		//std::map<std::string, std::string> Pin;

		//delete space and comment
		void DelComment(std::string &);
		void DelSpaceAndTab(std::string &Line);

		// define type name value
		void DefineType(std::string &Line);
		void DefineValue(std::string &Line);
		void DefineName(std::string &Line);

		//verification name Link chipset
		void ChipsetsOrLinksIsNotInFile();
		int VerifLink(std::string &Line);
		int VerifChipset(std::string &Line);

	private:
		//nom du fichier
		std::string _FileName;

		//variable type name value
		std::string _Type;
		std::string _Name;
		std::string _Value;

		// Chipset and link section
		bool _ChipsetInFile = false;
		bool _LinkInFile = false;
		std::map<std::string, nts::IComponent *> _MapInfoFile;
		std::map<std::string, nts::Clock *> _clocks;
		std::map<std::string, nts::Input *> _inputs;
		//std::map<std::string, nts::Output *> _outputs;

		//Section chipsets = 1 et section link = 2
		short _PosInFile;

		nts::IComponent &create(std::string const &, std::string const &);
		nts::Tristate transformValue(std::string const &);
	};
}

#endif //CPP_NANOTEKSPICE_PARSING_HPP
