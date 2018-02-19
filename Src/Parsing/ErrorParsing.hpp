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
	class ErrorParsing : public std::exception {
		public:
		ErrorParsing(const std::string &message, const std::string &indication);
		~ErrorParsing() throw() ;
		std::string const &GetMessage() const;
		std::string const &GetIndication() const;
		private:
		std::string _Message;
		std::string _Indication;
	};
}

#endif //CPP_NANOTEKSPICE_ERRORPARSING_HPP
