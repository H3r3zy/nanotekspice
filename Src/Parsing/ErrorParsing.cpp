/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include "ErrorParsing.hpp"

nts::ErrorParsing::ErrorParsing(const std::string &message, const std::string &indication) : _Message(message), _Indication(indication)
{
}

const std::string &nts::ErrorParsing::GetIndication() const
{
	return (_Indication);
}

const std::string &nts::ErrorParsing::GetMessage() const
{
	return (_Message);
}
