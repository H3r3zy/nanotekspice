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
		Parsing(std::string FileName);
		~Parsing();

		//getteur
		std::string GetNameFile();
		//std::map<std::string *, nts::IComponent> GetMapInfoFile();

		//parsing
		void ParseFile();
		void ParseArgument();
		void ParseLine(std::string Line);

		void StockChipset(std::string Line);
		//delete space and comment
		void DelComment(std::string &Line);

		void DelSpaceAndTab(std::string &Line);
		//define type name value
		void DefineName(std::string &Line);
		void DefineType(std::string &Line);
		void DefineValue(std::string &Line);

		//verification name Link chipset
		void ChipsetsOrLinksIsNotInFile();
		int VerifLink(std::string Line);
		int VerifChipset(std::string Line);
		int VerifUniqueName(std::string Line);

		//std::map<std::string *, nts::IComponent> GetMapInfoFile();
		//std::map<std::string, std::string> Pin;
		//void SetMapInfo();

	private:
		//vecteur pour l'ensemble des noms deja renseigné
		std::vector<std::string> _AllName;

		//nom du fichier
		std::string _FileName;

		//variable type name value
		std::string _Type;
		std::string _Name;
		std::string _Value;

		//chipset and link section
		bool _ChipsetInFile;
		bool _LinkInFile;
		//std::map<std::string *, nts::IComponent> _MapInfoFile;

		//Section chipsets = 1 et section link = 2
		short _PosInFile;
	};
}
#endif //CPP_NANOTEKSPICE_PARSING_HPP
