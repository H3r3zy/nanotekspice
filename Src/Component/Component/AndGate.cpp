/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "AndGate.hpp"

nts::AndGate::AndGate(nts::AndGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
}

nts::AndGate& nts::AndGate::operator=(nts::AndGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	return *this;
}

nts::Tristate nts::AndGate::compute(size_t pin)
{
	if (pin == 3) {
		nts::Tristate value1 = getPins(1);
		nts::Tristate value2 = getPins(2);
		if ((ISUNDEFINED(value1) && ISUNDEFINED(value2)) ||
			(ISUNDEFINED(value1) && ISTRUE(value2)) ||
			(ISTRUE(value1) && ISUNDEFINED(value2))) {
			_res = nts::UNDEFINED;
		} else if (ISTRUE(value1) && ISTRUE(value2)) {
			_res = nts::TRUE;
		} else {
			_res = nts::FALSE;
		}
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::AndGate::dump() const
{
	std::cout << "And Gate" << std::endl;
}

nts::AndGate *nts::AndGate::copy() const
{
	return new nts::AndGate(*this);
}