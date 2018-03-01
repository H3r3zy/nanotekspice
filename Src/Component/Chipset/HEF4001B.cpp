/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "NorGate.hpp"
#include "HEF4001B.hpp"

nts::HEF4001B::HEF4001B()
{
	_pin_number = 14;
	gate1 = new nts::NorGate();
	gate2 = new nts::NorGate();
	gate3 = new nts::NorGate();
	gate4 = new nts::NorGate();
	init();
}

nts::HEF4001B::~HEF4001B()
{
	delete gate1;
	delete gate2;
	delete gate3;
	delete gate4;
}

nts::HEF4001B::HEF4001B(nts::HEF4001B const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	gate1 = data.gate1;
	gate2 = data.gate2;
	gate3 = data.gate3;
	gate4 = data.gate4;
	init();
}

nts::HEF4001B& nts::HEF4001B::operator=(nts::HEF4001B const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	gate1 = data.gate1;
	gate2 = data.gate2;
	gate3 = data.gate3;
	gate4 = data.gate4;
	init();
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::HEF4001B const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::HEF4001B::compute(size_t pin)
{
	if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
		_res = getPins(pin);
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::HEF4001B::dump() const
{
	std::cout << "HEF4001B Chipset" << std::endl;
}

nts::HEF4001B *nts::HEF4001B::copy() const
{
	return new nts::HEF4001B(*this);
}

void nts::HEF4001B::init()
{
	auto _this = dynamic_cast<nts::IComponent *>(this);

	gate1->setLink(1, *_this, 1);
	gate1->setLink(2, *_this, 2);
	_this->setLink(3, *gate1, 3);

	gate2->setLink(1, *_this, 6);
	gate2->setLink(2, *_this, 5);
	_this->setLink(4, *gate2, 3);

	gate3->setLink(1, *_this, 8);
	gate3->setLink(2, *_this, 9);
	_this->setLink(10, *gate3, 3);

	gate4->setLink(1, *_this, 12);
	gate4->setLink(2, *_this, 13);
	_this->setLink(11, *gate4, 3);
}