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

nts::CD4008BMS::~CD4008BMS()
{
	delete gate1;
	delete gate2;
	delete gate3;
	delete gate4;
}

nts::CD4008BMS::CD4008BMS(nts::CD4008BMS const &toCopy)
{
}

nts::CD4008BMS &nts::CD4008BMS::operator=(nts::CD4008BMS const &toCopy)
{
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::CD4008BMS const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::CD4008BMS::compute(size_t pin)
{
	_res = getPins(pin);
	return _res;
}

void nts::CD4008BMS::dump() const
{
	std::cout << "CD4008BMS Chipset" << std::endl;
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