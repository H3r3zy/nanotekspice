/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "NandGate.hpp"
#include "CD4011B.hpp"

nts::CD4011B::CD4011B()
{
	_pin_number = 14;
	gate1 = new nts::NandGate();
	gate2 = new nts::NandGate();
	gate3 = new nts::NandGate();
	gate4 = new nts::NandGate();
	init();
}

nts::CD4011B::~CD4011B()
{
	delete gate1;
	delete gate2;
	delete gate3;
	delete gate4;
}

nts::CD4011B::CD4011B(nts::CD4011B const &data)
{
	gate1 = data.gate1;
	gate2 = data.gate2;
	gate3 = data.gate3;
	gate4 = data.gate4;
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	init();
}

nts::CD4011B& nts::CD4011B::operator=(nts::CD4011B const &data)
{
	gate1 = data.gate1;
	gate2 = data.gate2;
	gate3 = data.gate3;
	gate4 = data.gate4;
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	init();
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::CD4011B const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::CD4011B::compute(size_t pin)
{
	_res = getPins(pin);
	return _res;
}

void nts::CD4011B::dump() const
{
	std::cout << "CD4011B Chipset" << std::endl;
}

nts::CD4011B *nts::CD4011B::copy() const
{
	return new nts::CD4011B(*this);
}

void nts::CD4011B::init()
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