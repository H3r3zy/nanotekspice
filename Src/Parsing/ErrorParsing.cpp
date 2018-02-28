/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include "ErrorParsing.hpp"

nts::errorParsing::errorParsing(const std::string &message, const std::string &indication) : _message(message), _indication(indication)
{
}

nts::errorParsing::~errorParsing()
{
}

const std::string &nts::errorParsing::getIndication() const
{
	return (_indication);
}

const std::string &nts::errorParsing::getMessage() const
{
	return (_message);
}

