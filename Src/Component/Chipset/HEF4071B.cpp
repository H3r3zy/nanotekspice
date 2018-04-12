/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "HEF4071B.hpp"
#include "OrGate.hpp"

nts::HEF4071B::HEF4071B()
{
	_pin_number = 14;
	gate1 = new nts::OrGate();
	gate2 = new nts::OrGate();
	gate3 = new nts::OrGate();
	gate4 = new nts::OrGate();
	init();
}

nts::HEF4071B::~HEF4071B()
{
	delete gate1;
	delete gate2;
	delete gate3;
	delete gate4;
}

nts::HEF4071B::HEF4071B(nts::HEF4071B const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	gate1 = new nts::OrGate(*(nts::OrGate *) data.gate1);
	gate2 = new nts::OrGate(*(nts::OrGate *) data.gate2);
	gate3 = new nts::OrGate(*(nts::OrGate *) data.gate3);
	gate4 = new nts::OrGate(*(nts::OrGate *) data.gate4);
	init();
}

nts::HEF4071B& nts::HEF4071B::operator=(nts::HEF4071B const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	gate1 = new nts::OrGate(*(nts::OrGate *) data.gate1);
	gate2 = new nts::OrGate(*(nts::OrGate *) data.gate2);
	gate3 = new nts::OrGate(*(nts::OrGate *) data.gate3);
	gate4 = new nts::OrGate(*(nts::OrGate *) data.gate4);
	init();
	return *this;
}

nts::Tristate nts::HEF4071B::compute(size_t pin)
{
	_res = getPins(pin);
	return _res;
}

void nts::HEF4071B::dump() const
{
	std::cout << "HEF4071B Chipset" << std::endl;
}

nts::HEF4071B *nts::HEF4071B::copy() const
{
	return new nts::HEF4071B(*this);
}

void nts::HEF4071B::init()
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