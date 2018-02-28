/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "Clock.hpp"

nts::Clock::Clock()
{
	_value = nts::FALSE;
}

nts::Clock::Clock(nts::Clock const &toCopy)
{
	(void) toCopy;
	delete this;
}

nts::Clock &nts::Clock::operator=(nts::Clock const &toCopy)
{
	(void) toCopy;
	delete this;
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::Clock const &data)
{
	data.dump();
	return os;
}

void nts::Clock::dump() const
{
	std::cout << "Clock: " << tristate2Value(_value) << std::endl;
}

nts::Clock &nts::Clock::operator()()
{
	if (_value == nts::TRUE) {
		_value = nts::FALSE;
	} else if (_value == nts::FALSE) {
		_value = nts::TRUE;
	}
	return *this;
}