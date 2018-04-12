/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "CD4512B.hpp"

static const unsigned int inhibitPin = 10;
static const unsigned int ouputEnablePin = 15;
static const unsigned int addressA = 11;
static const unsigned int addressB = 12;
static const unsigned int addressC = 13;
static const unsigned int x0Pin = 1;
static const unsigned int x1Pin = 2;
static const unsigned int x2Pin = 3;
static const unsigned int x3Pin = 4;
static const unsigned int x4Pin = 5;
static const unsigned int x5Pin = 6;
static const unsigned int x6Pin = 7;
static const unsigned int x7Pin = 9;
static const std::map<unsigned int, unsigned int> outputInput = {
	{0, x0Pin},
	{1, x1Pin},
	{2, x2Pin},
	{3, x3Pin},
	{4, x4Pin},
	{5, x5Pin},
	{6, x6Pin},
	{7, x7Pin}
};

nts::CD4512B::CD4512B()
{
	_pin_number = 16;
}

nts::CD4512B::CD4512B(nts::CD4512B const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
}

nts::CD4512B& nts::CD4512B::operator=(nts::CD4512B const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	return *this;
}

nts::Tristate nts::CD4512B::compute(size_t pin)
{
	if (pin == 14) {
		nts::Tristate A = getPins(addressA);
		nts::Tristate B = getPins(addressB);
		nts::Tristate C = getPins(addressC);

		if (ISUNDEFINED(getPins(ouputEnablePin)) ||
			ISUNDEFINED(getPins(inhibitPin)) || ISUNDEFINED(A) ||
			ISUNDEFINED(B) || ISUNDEFINED(C)) {
			_res = nts::UNDEFINED;
		} else if (ISTRUE(getPins(ouputEnablePin))) {
			_res = nts::TRUE;
		} else if (ISTRUE(getPins(inhibitPin))) {
			_res = nts::FALSE;
		} else {
			_res = getPins(outputInput.at(A + B * 2 + C * 4));
		}
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::CD4512B::dump() const
{
	std::cout << "CD4512B Chipset" << std::endl;
}

nts::CD4512B *nts::CD4512B::copy() const
{
	return new nts::CD4512B(*this);
}