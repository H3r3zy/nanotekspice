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
		// Constructor
		Parsing(std::string fileName, int &ac, char **&av);

		// Destructor
		~Parsing() = default;

		// Getter
		std::map<std::string, nts::IComponent *> &getComponents();
		std::map<std::string, nts::Input *> &getInputs();
		std::map<std::string, nts::Output *> &getOutputs();
		std::map<std::string, nts::Clock *> &getClocks();
	private:
		// Parse
		void parseFile();
		void parseArgument();
		void parseLine(std::string &line);

		// Stock
		void stockChipset(std::string &line);
		void stockLinks(std::string &line);
		std::string stockNameArg(std::string &arg);
		std::string stockValueArg(std::string &arg);

		// Delete
		void delComment(std::string &line);
		void delSpaceAndTab(std::string &line);
		void defineName(std::string &line);
		void defineType(std::string &line);
		void defineValue(std::string &line);

		// Verification
		int verifLink(std::string &line);
		int verifChipset(std::string &line);
		void verifEmptyArg();
		void verifEqualArgument(std::string &arg);
		//int isComponent(std::string &name);
		void chipsetsOrLinksIsNotInFile();
		bool _chipsetInFile = false;
		bool _linkInFile = false;

		// Setter / Editer
		void modifValueWithArg();
		void setComponent();

		// Creation
		nts::IComponent &create(std::string const &, std::string const &);
		nts::Tristate transformValue(std::string const &);

		// Components Map
		std::map<std::string, nts::IComponent *> _components;
		std::map<std::string, nts::Clock *> _clocks;
		std::map<std::string, nts::Input *> _inputs;
		std::map<std::string, nts::Output *> _outputs;

		// Section chipstets = 1 and section link = 2
		short _posInFile = 0;

		std::vector<std::string> _nameArg;
		std::vector<std::string> _valueArg;
		std::map<std::string, std::string> _fileMap;
		std::string _fileName;
		std::string _type;
		std::string _name;
		std::string _value;
		std::vector<std::string> _nameLink;
		std::vector<std::string> _valueLink;
		int _ac;
		char **_av;
	};
}
#endif //CPP_NANOTEKSPICE_PARSING_HPP
