/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "NotGate.hpp"
#include "RSNorLatchComponent.hpp"

nts::RSNorLatchComponent::RSNorLatchComponent()
{
	_pin_number = 4;
	_not = new nts::NotGate();
	auto _this = dynamic_cast<nts::IComponent *>(this);

	_not->setLink(1, *this, 3);
	_this->setLink(4, *_not, 2);

}

nts::RSNorLatchComponent::~RSNorLatchComponent()
{
	delete _not;
}

nts::RSNorLatchComponent::RSNorLatchComponent(nts::RSNorLatchComponent const &toCopy)
{
}

nts::RSNorLatchComponent &nts::RSNorLatchComponent::operator=(nts::RSNorLatchComponent const &toCopy)
{
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::RSNorLatchComponent const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::RSNorLatchComponent::compute(size_t pin)
{
	if (pin == 3) {
		nts::Tristate value1 = getPins(1);
		nts::Tristate value2 = getPins(2);
		int undefinedNumber = UNDEFINEDVALUE(value1) + UNDEFINEDVALUE(value2);

		if (undefinedNumber != 0 || (ISTRUE(value1) && ISTRUE(value2))) {
			_res = nts::UNDEFINED;
		} else if (ISTRUE(value1)) {
			_res = nts::TRUE;
		} else if (ISTRUE(value2)) {
			_res = nts::FALSE;
		}
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::RSNorLatchComponent::dump() const
{
	std::cout << "RSNorLatchComponent Component" << std::endl;
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