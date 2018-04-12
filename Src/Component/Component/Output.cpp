/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "Output.hpp"

nts::Output::Output()
{
	_pin_number = 1;
}

nts::Output::Output(nts::Output const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = std::map<long unsigned int, std::size_t>(data._pinsArgument);
	_pins = std::map<long unsigned int, nts::IComponent *>(data._pins);
	_res = data._res;
}

nts::Output& nts::Output::operator=(nts::Output const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = std::map<long unsigned int, std::size_t>(data._pinsArgument);
	_pins = std::map<long unsigned int, nts::IComponent *>(data._pins);
	_res = data._res;
	return *this;
}

nts::Tristate nts::Output::compute(size_t pin)
{
	(void) pin;
	return getPins(1);
}

void nts::Output::dump() const
{
	std::cout << "Output" << std::endl;
}

nts::Output *nts::Output::copy() const
{
	return new nts::Output(*this);
}