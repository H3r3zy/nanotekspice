/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "CD4514BC.hpp"

const std::map<unsigned int, unsigned int> OUTPUTINPUT = {
	{11, 0},
	{9, 1},
	{10, 2},
	{8, 3},
	{7, 4},
	{6, 5},
	{5, 6},
	{4, 7},
	{18, 8},
	{17, 9},
	{20, 10},
	{19, 11},
	{14, 12},
	{13, 13},
	{16, 14},
	{15, 15}
};

nts::CD4514BC::CD4514BC()
{
	_pin_number = 24;
}

nts::CD4514BC::CD4514BC(nts::CD4514BC const &toCopy)
{
	(void) toCopy;
	delete this;
}

nts::CD4514BC &nts::CD4514BC::operator=(nts::CD4514BC const &toCopy)
{
	(void) toCopy;
	delete this;
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::CD4514BC const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::CD4514BC::compute(size_t pin)
{
	if (pin == 4 || pin == 5 || pin == 6 || pin == 7 || pin == 8 || pin == 9 || pin == 10 || pin == 11 ||
		pin == 13 || pin == 14 || pin == 15 || pin == 16 || pin == 17 || pin == 18 || pin == 19 || pin == 20) {
		nts::Tristate i1 = getPins(2);
		nts::Tristate i2 = getPins(3);
		nts::Tristate i3 = getPins(21);
		nts::Tristate i4 = getPins(22);

		if (ISTRUE(getPins(23))) {
			_res = nts::FALSE;
		} else if (ISUNDEFINED(getPins(23))) {
			_res = nts::UNDEFINED;
		} else {
			std::string str;
			str += tristate2Value(i4) += tristate2Value(i3) += tristate2Value(i2) += tristate2Value(i1);
			char res = truth.at(str)[OUTPUTINPUT.at(pin)];
			_res = value2Tristate(res);
		}
	} else {
		_res = getPins(pin);
	}
	return _res;
}

void nts::CD4514BC::dump() const
{
	std::cout << "CD4514BC Chipset" << std::endl;
}