/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "NotGate.hpp"
#include "CD4069UBC.hpp"

nts::CD4069UBC::CD4069UBC()
{
	_pin_number = 14;
	gate1 = new nts::NotGate();
	gate2 = new nts::NotGate();
	gate3 = new nts::NotGate();
	gate4 = new nts::NotGate();
	gate5 = new nts::NotGate();
	gate6 = new nts::NotGate();
	init();
}

nts::CD4069UBC::~CD4069UBC()
{
	delete gate1;
	delete gate2;
	delete gate3;
	delete gate4;
}

nts::CD4069UBC& nts::CD4069UBC::operator=(nts::CD4069UBC const &data)
{
	gate1 = new nts::NotGate(*(nts::NotGate *) data.gate1);
	gate2 = new nts::NotGate(*(nts::NotGate *) data.gate2);
	gate3 = new nts::NotGate(*(nts::NotGate *) data.gate3);
	gate4 = new nts::NotGate(*(nts::NotGate *) data.gate4);
	gate5 = new nts::NotGate(*(nts::NotGate *) data.gate5);
	gate6 = new nts::NotGate(*(nts::NotGate *) data.gate6);
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	init();
	return *this;
}

nts::CD4069UBC::CD4069UBC(nts::CD4069UBC const &data)
{
	gate1 = new nts::NotGate(*(nts::NotGate *) data.gate1);
	gate2 = new nts::NotGate(*(nts::NotGate *) data.gate2);
	gate3 = new nts::NotGate(*(nts::NotGate *) data.gate3);
	gate4 = new nts::NotGate(*(nts::NotGate *) data.gate4);
	gate5 = new nts::NotGate(*(nts::NotGate *) data.gate5);
	gate6 = new nts::NotGate(*(nts::NotGate *) data.gate6);
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	init();
}

nts::Tristate nts::CD4069UBC::compute(size_t pin)
{
	_res = getPins(pin);
	return _res;
}

void nts::CD4069UBC::dump() const
{
	std::cout << "CD4069UBC Chipset" << std::endl;
}

nts::CD4069UBC *nts::CD4069UBC::copy() const
{
	return new nts::CD4069UBC(*this);
}

void nts::CD4069UBC::init()
{
	auto _this = dynamic_cast<nts::IComponent *>(this);

	gate1->setLink(1, *_this, 1);
	_this->setLink(2, *gate1, 2);

	gate2->setLink(1, *_this, 3);
	_this->setLink(4, *gate2, 2);

	gate3->setLink(1, *_this, 5);
	_this->setLink(6, *gate3, 2);

	gate4->setLink(1, *_this, 9);
	_this->setLink(8, *gate4, 2);

	gate5->setLink(1, *_this, 11);
	_this->setLink(10, *gate5, 2);

	gate6->setLink(1, *_this, 13);
	_this->setLink(12, *gate6, 2);
}