/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "Input.hpp"

nts::Input::Input()
{
}

nts::Input::Input(nts::Input const &toCopy)
{
}

nts::Input &nts::Input::operator=(nts::Input const &toCopy)
{
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::Input const &data)
{
	return os;
}

nts::Tristate nts::Input::compute(size_t pin)
{
	return _value;
}

void nts::Input::setValue(nts::Tristate value) {
	_value = value;
}

void nts::Input::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
}

void nts::Input::dump() const
{
	std::cout << "Input" << std::endl;
	std::cout << "|=> value: ";
	if (_value == nts::UNDEFINED) {
		std::cout << "Undefined";
	} else if (_value == nts::TRUE) {
		std::cout << "True";
	} else {
		std::cout << "False";
	}
	std::cout << std::endl;
}