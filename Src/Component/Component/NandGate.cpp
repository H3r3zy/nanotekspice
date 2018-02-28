/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "NandGate.hpp"

nts::NandGate::NandGate(nts::NandGate const &toCopy)
{
	(void) toCopy;
	delete this;
}

nts::NandGate &nts::NandGate::operator=(nts::NandGate const &toCopy)
{
	(void) toCopy;
	delete this;
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
}