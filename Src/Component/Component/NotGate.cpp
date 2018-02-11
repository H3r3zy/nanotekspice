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

nts::NotGate::NotGate(nts::NotGate const &toCopy)
{
}

nts::NotGate &nts::NotGate::operator=(nts::NotGate const &toCopy)
{
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::NotGate const &data)
{
	data.dump();
	return os;
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
	try {
		std::cout << "vvv Input vvv" << std::endl;
		if (_pins.at(1))
			_pins.at(1)->dump();
	} catch(std::out_of_range &e) {

	}
	std::cout << "|=> output: ";
	if (_res == nts::UNDEFINED)
		std::cout << "Undefined";
	if (_res == nts::FALSE)
		std::cout << "False";
	if (_res == nts::TRUE)
		std::cout << "True";
	std::cout << std::endl;
}