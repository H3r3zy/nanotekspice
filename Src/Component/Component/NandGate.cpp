/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "NandGate.hpp"

nts::NandGate::NandGate()
{
}

nts::NandGate::NandGate(nts::NandGate const &toCopy)
{
}

nts::NandGate &nts::NandGate::operator=(nts::NandGate const &toCopy)
{
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::NandGate const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::NandGate::compute(size_t pin)
{
	if (pin == 3) {
		nts::Tristate value1 = getPins(1);
		nts::Tristate value2 = getPins(2);
		if (ISTRUE(value1) && ISTRUE(value2)) {
			_res = nts::FALSE;
		} else if (ISFALSE(value1) || ISFALSE(value2)) {
			_res = nts::TRUE;
		} else {
			_res = nts::UNDEFINED;
		}
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::NandGate::dump() const
{
	std::cout << "Nand Gate" << std::endl;
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