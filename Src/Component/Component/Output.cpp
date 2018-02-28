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

nts::Output::Output(nts::Output const &toCopy)
{
	(void) toCopy;
	delete this;
}

nts::Output &nts::Output::operator=(nts::Output const &toCopy)
{
	(void) toCopy;
	delete this;
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::Output const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::Output::compute(size_t pin)
{
	return getPins(pin);
}

void nts::Output::dump() const
{
	std::cout << "Output" << std::endl;
}