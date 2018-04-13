/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "CD4094BC.hpp"

static const std::map<int, int> pinLink = {
	{4, 0},
	{5, 1},
	{6, 2},
	{7, 3},
	{14, 4},
	{13, 5},
	{12, 6},
	{11, 7}
};

nts::CD4094BC::CD4094BC()
{
	_pin_number = 16;
}

nts::CD4094BC::CD4094BC(nts::CD4094BC const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	lastClock = data.lastClock;
	tmp = data.tmp;
}

nts::CD4094BC& nts::CD4094BC::operator=(nts::CD4094BC const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	lastClock = data.lastClock;
	tmp = data.tmp;
	return *this;
}

nts::CD4094BC* nts::CD4094BC::copy() const
{
	return new nts::CD4094BC(*this);
}

nts::Tristate nts::CD4094BC::compute(std::size_t pin)
{
	if ((pin >= 4 && pin <= 7) || (pin >= 9 && pin <= 14)) {
		nts::Tristate Strobe = getPins(1);
		nts::Tristate Data = getPins(2);
		nts::Tristate Clock = getPins(3);
		nts::Tristate Enable = getPins(15);

		if (pin == 9 || pin == 10) {
			if (lastClock == nts::FALSE && Clock == nts::TRUE) {
				if (pin == 9) {
					_res = _data[6];
					_data[8] = _res;
				}
				else {
					_res = _data[9];
				}
			} else {
				if (pin == 9) {
					_res = _data[9];
				} else {
					_res = _data[6];
					_data[9] = _res;
				}
			}
		} else if (Enable == nts::FALSE) {
			_res = nts::TRUE;
		} else {
			if (lastClock == nts::FALSE && Clock == nts::TRUE && first && Strobe) {
				first = false;
				_data[7] = _data[6];
				_data[6] = _data[5];
				_data[5] = _data[4];
				_data[4] = _data[3];
				_data[3] = _data[2];
				_data[2] = _data[1];
				_data[1] = _data[0];
				_data[0] = Data;
			}
			_res = _data[pinLink.at((int) pin)];
		}

		tmp = Clock;
	} else {
		_res = getPins(pin);
	}
	return _res;
}

void nts::CD4094BC::dump() const
{
	std::cout << "CD4094BC Chipset" << std::endl;
}

void nts::CD4094BC::reset()
{
	lastClock = tmp;
	first = true;
}
