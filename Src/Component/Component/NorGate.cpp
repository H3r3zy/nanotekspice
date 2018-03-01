/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "NorGate.hpp"

std::ostream &operator<<(std::ostream &os, nts::NorGate const &data)
{
	data.dump();
	return os;
}

nts::NorGate::NorGate(nts::NorGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
}

nts::NorGate& nts::NorGate::operator=(nts::NorGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	return *this;
}

nts::Tristate nts::NorGate::compute(size_t pin)
{
	if (pin == 3) {
		nts::Tristate value1 = getPins(1);
		nts::Tristate value2 = getPins(2);
		if (ISFALSE(value1) && ISFALSE(value2)) {
			_res = nts::TRUE;
		} else if (ISTRUE(value1) || ISTRUE(value2)) {
			_res = nts::FALSE;
		} else {
			_res = nts::UNDEFINED;
		}
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::NorGate::dump() const
{
	std::cout << "Nor Gate" << std::endl;
}

nts::NorGate *nts::NorGate::copy() const
{
	return new nts::NorGate(*this);
}