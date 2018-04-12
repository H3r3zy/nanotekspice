/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/


#include "NorGate.hpp"
#include "CD4008BMS.hpp"

nts::CD4008BMS::CD4008BMS()
{
	_pin_number = 16;
	gate1 = new nts::FullAdderComponent();
	gate2 = new nts::FullAdderComponent();
	gate3 = new nts::FullAdderComponent();
	gate4 = new nts::FullAdderComponent();
	init();
}

nts::CD4008BMS::~CD4008BMS()
{
	delete gate1;
	delete gate2;
	delete gate3;
	delete gate4;
}

nts::CD4008BMS::CD4008BMS(nts::CD4008BMS const &data)
{
	gate1 = new nts::FullAdderComponent(*(nts::FullAdderComponent *) data.gate1);
	gate2 = new nts::FullAdderComponent(*(nts::FullAdderComponent *) data.gate2);
	gate3 = new nts::FullAdderComponent(*(nts::FullAdderComponent *) data.gate3);
	gate4 = new nts::FullAdderComponent(*(nts::FullAdderComponent *) data.gate4);
	_pin_number = data._pin_number;
	_pins = data._pins;
	_pinsArgument = data._pinsArgument;
	_res = data._res;
	init();
}

nts::CD4008BMS& nts::CD4008BMS::operator=(nts::CD4008BMS const &data)
{
	gate1 = new nts::FullAdderComponent(*(nts::FullAdderComponent *) data.gate1);
	gate2 = new nts::FullAdderComponent(*(nts::FullAdderComponent *) data.gate2);
	gate3 = new nts::FullAdderComponent(*(nts::FullAdderComponent *) data.gate3);
	gate4 = new nts::FullAdderComponent(*(nts::FullAdderComponent *) data.gate4);
	_pin_number = data._pin_number;
	_pins = data._pins;
	_pinsArgument = data._pinsArgument;
	_res = data._res;
	init();
	return *this;
}

nts::Tristate nts::CD4008BMS::compute(size_t pin)
{
	_res = getPins(pin);
	return _res;
}

void nts::CD4008BMS::dump() const
{
	std::cout << "CD4008BMS Chipset" << std::endl;
}

nts::CD4008BMS *nts::CD4008BMS::copy() const
{
	return new nts::CD4008BMS(*this);
}

void nts::CD4008BMS::init()
{
	auto _this = dynamic_cast<nts::IComponent *>(this);

	gate1->setLink(1, *_this, 7);
	gate1->setLink(2, *_this, 6);
	gate1->setLink(3, *_this, 9);
	_this->setLink(10, *gate1, 5);

	gate2->setLink(1, *_this, 5);
	gate2->setLink(2, *_this, 4);
	gate2->setLink(3, *gate1, 4);
	_this->setLink(11, *gate2, 5);

	gate3->setLink(1, *_this, 3);
	gate3->setLink(2, *_this, 2);
	gate3->setLink(3, *gate2, 4);
	_this->setLink(12, *gate3, 5);

	gate4->setLink(1, *_this, 1);
	gate4->setLink(2, *_this, 15);
	gate4->setLink(3, *gate3, 4);
	_this->setLink(14, *gate4, 4);
	_this->setLink(13, *gate4, 5);
}