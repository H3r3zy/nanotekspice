/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <iostream>
#include "CD4013BC.hpp"

nts::CD4013BC::CD4013BC()
{
	_pin_number = 14;
}

nts::CD4013BC::CD4013BC(nts::CD4013BC const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	lastClock1 = data.lastClock1;
	lastClock2 = data.lastClock2;
	tmp1 = data.tmp1;
	tmp2 = data.tmp2;
	first = data.first;
}

nts::CD4013BC& nts::CD4013BC::operator=(nts::CD4013BC const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	lastClock1 = data.lastClock1;
	lastClock2 = data.lastClock2;
	tmp1 = data.tmp1;
	tmp2 = data.tmp2;
	first = data.first;
	return *this;
}

nts::Tristate nts::CD4013BC::compute(std::size_t pin)
{
	if (pin == 1 || pin == 2 || pin == 12 || pin == 13) {
		nts::Tristate C = (pin < 3) ? (getPins(3)) : (getPins(11));
		nts::Tristate D = (pin < 3) ? (getPins(5)) : (getPins(9));
		nts::Tristate R = (pin < 3) ? (getPins(4)) : (getPins(10));
		nts::Tristate S = (pin < 3) ? (getPins(6)) : (getPins(8));
		nts::Tristate Q = (pin < 3) ? (saveQ1) : (saveQ2);
		nts::Tristate NQ = (pin < 3) ? (saveNQ1) : (saveNQ2);

		if (R == nts::UNDEFINED || S == nts::UNDEFINED) {
			_res = nts::UNDEFINED;
			if (pin == 1 || pin == 13) {
				if (pin == 1)
					saveQ1 = nts::UNDEFINED;
				else
					saveQ2 = nts::UNDEFINED;
			} else {
				if (pin == 2)
					saveNQ1 = nts::UNDEFINED;
				else
					saveNQ2 = nts::UNDEFINED;
			}
		} else if (S == nts::TRUE) {
			if (pin == 1 || pin == 13) {
				_res = nts::TRUE;
				if (pin == 1)
					saveQ1 = nts::TRUE;
				else
					saveQ2 = nts::TRUE;
			} else {
				_res = R;
				if (pin == 2)
					saveNQ1 = R;
				else
					saveNQ2 = R;
			}
		} else if (R == TRUE) {
			if (pin == 1 || pin == 13) {
				_res = nts::FALSE;
				if (pin == 1)
					saveQ1 = nts::FALSE;
				else
					saveQ2 = nts::FALSE;
			} else {
				_res = nts::TRUE;
				if (pin == 2)
					saveNQ1 = nts::TRUE;
				else
					saveNQ2 = nts::TRUE;
			}
		} else if ((pin < 3 && lastClock1 == nts::TRUE && C == nts::FALSE) ||
			(pin > 3 && lastClock2 == nts::TRUE && C == nts::FALSE)) {
			if (pin == 1 || pin == 13) {
				_res = Q;
				if (pin == 1)
					saveQ1 = _res;
				else
					saveQ2 = _res;
			} else {
				_res = NQ;
				if (pin == 2)
					saveNQ1 = _res;
				else
					saveNQ2 = _res;
			}
		} else if (D == nts::TRUE) {
			if (pin == 1 || pin == 13) {
				_res = D;
				if (pin == 1)
					saveQ1 = _res;
				else
					saveQ2 = _res;
			} else {
				_res = nts::FALSE;
				if (pin == 2)
					saveNQ1 = _res;
				else
					saveNQ2 = _res;
			}
		} else if (D == nts::FALSE) {
			if (pin == 1 || pin == 13) {
				_res = D;
				if (pin == 1)
					saveQ1 = _res;
				else
					saveQ2 = _res;
			} else {
				_res = nts::TRUE;
				if (pin == 2)
					saveNQ1 = _res;
				else
					saveNQ2 = _res;
			}
		} else {
			_res = nts::UNDEFINED;
			if (pin == 1 || pin == 13) {
				if (pin == 1)
					saveQ1 = _res;
				else
					saveQ2 = _res;
			} else {
				if (pin == 2)
					saveNQ1 = _res;
				else
					saveNQ2 = _res;
			}
		}
		if (pin < 3)
			tmp1 = C;
		else
			tmp2 = C;
	} else {
		_res = getPins(pin);
	}
	return _res;
}

void nts::CD4013BC::dump() const
{
	std::cout << "CD4013BC Chipset" << std::endl;
}

nts::CD4013BC* nts::CD4013BC::copy() const
{
	return new nts::CD4013BC(*this);
}

void nts::CD4013BC::reset()
{
	cycle = 0;
	lastClock1 = tmp1;
	lastClock2 = tmp2;
}