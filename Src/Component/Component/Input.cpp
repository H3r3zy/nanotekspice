/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "Input.hpp"

std::ostream &operator<<(std::ostream &os, nts::Input const &data)
{
	data.dump();
	return os;
}

nts::Input::Input(nts::Input const &data)
{
	_value = data._value;
	_res = data._res;
	_pinsArgument = data._pinsArgument;
	_pin_number = data._pin_number;
	_res = data._res;
}

nts::Input& nts::Input::operator=(nts::Input const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	_value = data._value;
	return *this;
}

nts::Tristate nts::Input::compute(size_t pin)
{
	(void) pin;
	return _value;
}

void nts::Input::setValue(nts::Tristate value) {
	_value = value;
}

void nts::Input::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	(void) pin;
	(void) other;
	(void) otherPin;
}

void nts::Input::dump() const
{
	std::cout << "Input" << std::endl;
}

nts::Input *nts::Input::copy() const
{
	auto tmp = new nts::Input(*this);
	return tmp;
}