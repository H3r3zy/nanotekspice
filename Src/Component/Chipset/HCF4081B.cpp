/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "HCF4081B.hpp"

nts::HCF4081B::HCF4081B()
{
	_pin_number = 14;
	gate1 = new nts::AndGate();
	gate2 = new nts::AndGate();
	gate3 = new nts::AndGate();
	gate4 = new nts::AndGate();
	init();
}

nts::HCF4081B::~HCF4081B()
{
	delete gate1;
	delete gate2;
	delete gate3;
	delete gate4;
}

nts::HCF4081B::HCF4081B(nts::HCF4081B const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	gate1 = new nts::AndGate(*(nts::AndGate *) data.gate1);
	gate2 = new nts::AndGate(*(nts::AndGate *) data.gate2);
	gate3 = new nts::AndGate(*(nts::AndGate *) data.gate3);
	gate4 = new nts::AndGate(*(nts::AndGate *) data.gate4);
	init();
}

nts::HCF4081B& nts::HCF4081B::operator=(nts::HCF4081B const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	gate1 = new nts::AndGate(*(nts::AndGate *) data.gate1);
	gate2 = new nts::AndGate(*(nts::AndGate *) data.gate2);
	gate3 = new nts::AndGate(*(nts::AndGate *) data.gate3);
	gate4 = new nts::AndGate(*(nts::AndGate *) data.gate4);
	init();
	return *this;
}

nts::Tristate nts::HCF4081B::compute(size_t pin)
{
	_res = getPins(pin);
	return _res;
}

void nts::HCF4081B::dump() const
{
	std::cout << "HCF4081B Chipset" << std::endl;
}

nts::HCF4081B *nts::HCF4081B::copy() const
{
	return new nts::HCF4081B(*this);
}

void nts::HCF4081B::init()
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