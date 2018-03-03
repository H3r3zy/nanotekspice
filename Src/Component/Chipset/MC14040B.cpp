/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <bitset>
#include "MC14040B.hpp"
#include "OrGate.hpp"

static const std::map<unsigned int, unsigned int> OUTPUTINPUT = {
	{9, 0},
	{7, 1},
	{6, 2},
	{5, 3},
	{3, 4},
	{2, 5},
	{4, 6},
	{13, 7},
	{12, 8},
	{14, 9},
	{15, 10},
	{1, 11}
};

nts::MC14040B::MC14040B()
{
	_pin_number = 16;
}


nts::MC14040B::MC14040B(nts::MC14040B const &data)
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

nts::MC14040B& nts::MC14040B::operator=(nts::MC14040B const &data)
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

std::ostream &operator<<(std::ostream &os, nts::MC14040B const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::MC14040B::compute(size_t pin)
{
	int c = cycle;
	nts::Tristate inhib = getPins(11);
	nts::Tristate clock = getPins(10);
	if (pin == 1 || pin == 2 || pin == 3 || pin == 4 || pin == 5 ||
		pin == 6 || pin == 7 || pin == 9 || pin == 12 || pin == 13 ||
		pin == 14 || pin == 15) {
		if (inhib != nts::FALSE) {
			_res = inhib;
			tmp = clock;
		} else {
			if (clock == nts::FALSE && lastClock == nts::TRUE && ((c == 0 && !first) || (first))) {
				_counter++;
				first = false;
			}
			if (_counter > 4096)
				_counter = 0;
			std::string bin = std::bitset<12>(_counter).to_string();
			if (OUTPUTINPUT.at((unsigned int) pin) < bin.size() &&
				bin[OUTPUTINPUT.at((unsigned int) pin)] == '1')
				_res = nts::TRUE;
			else
				_res = nts::FALSE;
			tmp = clock;
		}
	} else {
		_res = getPins(pin);
	}
	return _res;
}

void nts::MC14040B::dump() const
{
	std::cout << "MC14040B Chipset" << std::endl;
}

nts::MC14040B *nts::MC14040B::copy() const
{
	return new nts::MC14040B(*this);
}

void nts::MC14040B::reset()
{
	cycle = 0;
	lastClock = tmp;
}