/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "OrGate.hpp"

nts::OrGate::OrGate(nts::OrGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
}

nts::OrGate& nts::OrGate::operator=(nts::OrGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	return *this;
}

nts::Tristate nts::OrGate::compute(size_t pin)
{
	if (pin == 3) {
		nts::Tristate value1 = getPins(1);
		nts::Tristate value2 = getPins(2);
		if (ISFALSE(value1) && ISFALSE(value2)) {
			_res = nts::FALSE;
		} else if (ISTRUE(value1) || ISTRUE(value2)) {
			_res = nts::TRUE;
		} else {
			_res = nts::UNDEFINED;
		}
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::OrGate::dump() const
{
	std::cout << "Or Gate" << std::endl;
}

nts::OrGate *nts::OrGate::copy() const
{
	return new nts::OrGate(*this);
}