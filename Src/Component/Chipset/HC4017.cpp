/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "HC4017.hpp"

static const std::map<unsigned int, unsigned int> OUTPUTINPUT = {
	{1, 3},
	{2, 2},
	{3, 4},
	{4, 7},
	{5, 10},
	{6, 1},
	{7, 5},
	{8, 6},
	{9, 9},
	{10, 11}
};

nts::HC4017::HC4017()
{
	_pin_number = 16;
}


nts::HC4017::HC4017(nts::HC4017 const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	_counter = data._counter;
	lastClock = data.lastClock;
	tmp = data.tmp;
	first = data.first;
}

nts::HC4017& nts::HC4017::operator=(nts::HC4017 const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	_counter = data._counter;
	lastClock = data.lastClock;
	tmp = data.tmp;
	first = data.first;
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::HC4017 const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::HC4017::compute(size_t pin)
{
	int c = cycle;
	nts::Tristate inhib = getPins(15);
	nts::Tristate clock = getPins(14);
	if (pin == 1 || pin == 2 || pin == 3 || pin == 4 || pin == 5 ||
		pin == 6 || pin == 7 || pin == 9 || pin == 10 || pin == 11 || pin == 12) {
		if (inhib == nts::TRUE) {
			tmp = clock;
			_counter = 1;
		} else if (clock == nts::TRUE && lastClock == nts::FALSE && ((c == 0 && !first) || (first))) {
			_counter++;
			first = false;
		}
		if (_counter > 10)
			_counter = 1;
		if ((_counter != 0 && OUTPUTINPUT.at(_counter) == pin) || (_counter < 6 && pin == 12 	))
			_res = nts::TRUE;
		else
			_res = nts::FALSE;
		tmp = clock;
	} else {
		_res = getPins(pin);
	}
	return _res;
}

void nts::HC4017::dump() const
{
	std::cout << "HC4017 Chipset" << std::endl;
}

nts::HC4017 *nts::HC4017::copy() const
{
	return new nts::HC4017(*this);
}

void nts::HC4017::reset()
{
	cycle = 0;
	lastClock = tmp;
}