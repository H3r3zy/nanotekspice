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
#include "Output.hpp"
#include "ErrorParsing.hpp"
#include "IComponent.hpp"

namespace nts {
	class Parsing {
	public:
		Parsing(std::string const &FileName, int &ac, char **&av);
		~Parsing() = default;

		// Getter
		std::map<std::string, nts::IComponent *> &getComponents();
		std::map<std::string, nts::Input *> &getInputs();
		std::map<std::string, nts::Output *> &getOutputs();
		std::map<std::string, nts::Clock *> &getClocks();

	private:
		void ParseFile();
		void ParseArgument();
		void ParseLine(std::string &Line);
		void StockChipset(std::string &Line);
		void StockLinks(std::string &Line);
		void DelComment(std::string &Line);
		void DelSpaceAndTab(std::string &Line);
		void DefineName(std::string &Line);
		void DefineType(std::string &Line);
		void DefineValue(std::string &Line);
		void ChipsetsOrLinksIsNotInFile();
		int VerifLink(std::string &Line);
		int VerifChipset(std::string &Line);
		void ModifValueWithArg();
		void VerifEmptyArg();
		void VerifEqualArgument(std::string &Arg);
		std::string StockNameArg(std::string &Arg);
		std::string StockValueArg(std::string &Arg);
		void setComponent();
		std::vector<std::string> _NameArg;
		std::vector<std::string> _ValueArg;
		std::map<std::string, std::string> _FileMap;
		std::string _FileName;
		std::string _Type;
		std::string _Name;
		std::string _Value;

		// Chipset and link section
		bool _ChipsetInFile = false;
		bool _LinkInFile = false;

		// Components Map
		std::map<std::string, nts::IComponent *> _components;
		std::map<std::string, nts::Clock *> _clocks;
		std::map<std::string, nts::Input *> _inputs;
		std::map<std::string, nts::Output *> _outputs;

		//Section chipsets = 1 et section link = 2
		short _PosInFile = 0;

		nts::IComponent &create(std::string const &, std::string const &);
		nts::Tristate transformValue(std::string const &);
		std::vector<std::string> _NameLink;
		std::vector<std::string> _ValueLink;
		int _ac;
		char **_av;

	};
}

#endif //CPP_NANOTEKSPICE_PARSING_HPP
