/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_PARSING2_HPP
#define CPP_NANOTEKSPICE_PARSING2_HPP

#include <map>
#include <vector>
#include <regex>
#include <string>
#include <fstream>
#include "IComponent.hpp"
#include "Clock.hpp"
#include "Output.hpp"
#include "Input.hpp"
#include "Factory.hpp"

namespace nts {
	class Parsing {
	public:
		// Constructor
		Parsing(std::string &fileName, char **&av);

		// Destructor
		~Parsing();

		// Getter
		std::map<std::string, nts::IComponent *> &getComponents();
		std::map<std::string, nts::Input *> &getInputs();
		std::map<std::string, nts::Output *> &getOutputs();
		std::map<std::string, nts::Clock *> &getClocks();

	private:
		// Factory
		Factory<nts::IComponent> factory;

		// Components Map
		std::map<std::string, nts::IComponent *> _components;
		std::map<std::string, nts::Clock *> _clocks;
		std::map<std::string, nts::Input *> _inputs;
		std::map<std::string, nts::Output *> _outputs;

		// Section (.chipsets:, .links:)
		std::string _sectionKey;
		std::map<std::string, void (nts::Parsing::*)(void)> _sections = {
			{"^( |\t)*\\.links:( |\t)*$", &nts::Parsing::links},
			{"^( |\t)*\\.chipsets:( |\t)*$", &nts::Parsing::components}
		};
		bool checkSection();
		void links();
		void components();
		void setLinks();

		// Parsing
		std::string _line;
		std::ifstream _file;

		void parseLine();
		void delComment();

		void verifArg(char **&arg);
		std::map<std::string, std::string> _arguments;

		typedef struct {
			std::string name1;
			std::size_t pin1;
			std::string name2;
			std::size_t pin2;
		} linkStruct;
		std::vector<nts::Parsing::linkStruct> _links;
		nts::IComponent *create(std::string &type, std::string &value);
	};
}

#define ISINMAP(name, map) ((map).find(name) != (map).end())

#endif //CPP_NANOTEKSPICE_PARSING2_HPP
