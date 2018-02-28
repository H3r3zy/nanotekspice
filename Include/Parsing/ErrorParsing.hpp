/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/
#ifndef CPP_NANOTEKSPICE_ERRORPARSING_HPP
#define CPP_NANOTEKSPICE_ERRORPARSING_HPP

#include <iostream>
#include <string>
#include <exception>

namespace nts {
	class errorParsing : public std::exception {
	public:
		// Constructor
		errorParsing(const std::string &message, const std::string &indication);

		// Destructor
		~errorParsing() = default;

		// Getter
		std::string const &getMessage() const;
		std::string const &getIndication() const;

	private:
		std::string _message;
		std::string _indication;
	};
}

#endif //CPP_NANOTEKSPICE_ERRORPARSING_HPP
