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
		Parsing(std::string fileName, int ac, char **av);
		~Parsing();
		std::string getNameFile();
		std::map<std::string, nts::IComponent *> getMapInfoFile();
		std::map<std::string, nts::IComponent *> getMapInput();
		std::map<std::string, nts::IComponent *> getMapOutput();
		std::map<std::string, nts::IComponent *> getMapClock();
	private:
		void parseFile(void);
		int isComponent(std::string name);
		void parseArgument(void);
		void parseLine(std::string Line);
		void stockChipset(std::string Line);
		void stockLinks(std::string &Line);
		void delComment(std::string &Line);
		void delSpaceAndTab(std::string &Line);
		void defineName(std::string &Line);
		void defineType(std::string &Line);
		void defineValue(std::string &Line);
		void chipsetsOrLinksIsNotInFile();
		int verifLink(std::string Line);
		int verifChipset(std::string Line);
		int verifUniqueName(std::string Line);
		void modifValueWithArg(void);
		void verifEmptyArg(void);
		void verifEqualArgument(std::string &Arg);
		std::string stockNameArg(std::string &Arg);
		std::string stockValueArg(std::string &Arg);
		int verifNameExiste(std::string);
		std::vector<std::string> _allName;
		void setMapInfo(void);
		std::vector<std::string> _nameArg;
		std::vector<std::string> _valueArg;
		std::map<std::string, std::string> _fileMap;
		std::string _fileName;
		std::string _type;
		std::string _name;
		std::string _value;
		std::vector<std::string> _nameLink;
		std::vector<std::string> _valueLink;
		bool _chipsetInFile;
		bool _linkInFile;
		std::map<std::string, nts::IComponent *> _mapInfoFile;
		std::map<std::string, nts::IComponent *> _mapInputFile;
		std::map<std::string, nts::IComponent *> _mapOutputFile;
		std::map<std::string, nts::IComponent *> _mapClockFile;
		short _posInFile;
		int _ac;
		char **_av;
	};
}
#endif //CPP_NANOTEKSPICE_PARSING_HPP
