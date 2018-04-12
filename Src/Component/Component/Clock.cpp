/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "Clock.hpp"

nts::Clock::Clock()
{
	_value = nts::FALSE;
}

nts::Clock::Clock(nts::Clock const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	_value = data._value;
}

nts::Clock& nts::Clock::operator=(nts::Clock const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	_value = data._value;
	return *this;
}

void nts::Clock::dump() const
{
	std::cout << "Clock: " << tristate2Value(_value) << std::endl;
}

nts::Tristate nts::Clock::compute(size_t pin)
{
	(void) pin;
	return _value;
}

void nts::Clock::setValue(nts::Tristate value) {
	_value = value;
}

void nts::Clock::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	(void) pin;
	(void) other;
	(void) otherPin;
}

nts::Clock &nts::Clock::operator()()
{
	if (_value == nts::TRUE) {
		_value = nts::FALSE;
	} else if (_value == nts::FALSE) {
		_value = nts::TRUE;
	}
	return *this;
}

nts::Clock *nts::Clock::copy() const
{
	return new nts::Clock(*this);
}