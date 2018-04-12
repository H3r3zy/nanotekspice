/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "NotGate.hpp"

nts::NotGate::NotGate()
{
	_pin_number = 2;
}

nts::NotGate::NotGate(nts::NotGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
}

nts::NotGate& nts::NotGate::operator=(nts::NotGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	return *this;
}

nts::Tristate nts::NotGate::compute(size_t pin)
{
	if (pin == 2) {
		nts::Tristate value = getPins(1);
		if (ISTRUE(value)) {
			_res = nts::FALSE;
		} else if (ISFALSE(value)) {
			_res = nts::TRUE;
		} else {
			_res = nts::UNDEFINED;
		}
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::NotGate::dump() const
{
	std::cout << "Not Gate" << std::endl;
}

nts::NotGate *nts::NotGate::copy() const
{
	return  new nts::NotGate(*this);
}