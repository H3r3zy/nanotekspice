/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "AbstractComponent.hpp"

void nts::AbstractComponent::setLink(std::size_t pin, nts::IComponent &other,
	size_t otherPin
)
{
	if (pin > 0 && pin <= _pin_number) {
		_pins[pin] = &other;
		_pinsArgument[pin] = otherPin;
	} else {
		throw std::out_of_range("Pin is out of range");
	}
}

nts::Tristate nts::AbstractComponent::getPins(size_t pin)
{
	cycle++;
	if (cycle > _maxUsePerCycle)
		return nts::UNDEFINED;
	nts::Tristate res;
	try {
		res = (pin > 0 && pin <= _pin_number) ?
			_pins.at(pin)->compute(_pinsArgument[pin]) :
			nts::UNDEFINED;
	} catch (std::exception &e) {
		res = nts::UNDEFINED;
	}
	return res;
}

std::string &nts::AbstractComponent::tristate2Value(nts::Tristate tristate) const
{
	std::string *res;
	if (tristate == nts::UNDEFINED) {
		res = new std::string("U");
	} else if (tristate == nts::TRUE) {
		res = new std::string("1");
	} else {
		res = new std::string("0");
	}
	return *res;
}

nts::Tristate nts::AbstractComponent::value2Tristate(std::string &value) const
{
	nts::Tristate res;
	if (value == "U") {
		res = nts::UNDEFINED;
	} else if (value == "1") {
		res = nts::TRUE;
	} else {
		res = nts::FALSE;
	}
	return res;
}

nts::Tristate nts::AbstractComponent::value2Tristate(const char value) const
{
	nts::Tristate res;
	if (value == 'U') {
		res = nts::UNDEFINED;
	} else if (value == '1') {
		res = nts::TRUE;
	} else {
		res = nts::FALSE;
	}
	return res;
}

void nts::AbstractComponent::reset()
{
	cycle = 0;
}

std::ostream &operator<<(std::ostream &os, nts::AbstractComponent const &data)
{
	data.dump();
	return os;
}