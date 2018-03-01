/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "XorGate.hpp"

std::ostream &operator<<(std::ostream &os, nts::XorGate const &data)
{
	data.dump();
	return os;
}

nts::XorGate::XorGate(nts::XorGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
}

nts::XorGate& nts::XorGate::operator=(nts::XorGate const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	return *this;
}

nts::Tristate nts::XorGate::compute(size_t pin)
{
	if (pin == 3) {
		nts::Tristate value1 = getPins(1);
		nts::Tristate value2 = getPins(2);
		if (ISUNDEFINED(value1) || ISUNDEFINED(value2)) {
			_res = nts::UNDEFINED;
		} else if (value1 == value2) {
			_res = nts::FALSE;
		} else {
			_res = nts::TRUE;
		}
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::XorGate::dump() const
{
	std::cout << "Xor Gate" << std::endl;
}

nts::XorGate *nts::XorGate::copy() const
{
	return new nts::XorGate(*this);
}