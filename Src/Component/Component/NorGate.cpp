/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "NorGate.hpp"

nts::NorGate::NorGate()
{
}

nts::NorGate::NorGate(nts::NorGate const &toCopy)
{
}

nts::NorGate &nts::NorGate::operator=(nts::NorGate const &toCopy)
{
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::NorGate const &data)
{
	data.dump();
	return os;
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
	try {
		std::cout << "vvv Input 1 vvv" << std::endl;
		if (_pins.at(1))
			_pins.at(1)->dump();
		std::cout << "vvv Input 2 vvv" << std::endl;
		if (_pins.at(2))
			_pins.at(2)->dump();
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