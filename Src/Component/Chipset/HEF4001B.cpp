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

nts::HEF4001B::~HEF4001B()
{
	delete gate1;
	delete gate2;
	delete gate3;
	delete gate4;
}

nts::HEF4001B::HEF4001B(nts::HEF4001B const &toCopy)
{
}

nts::HEF4001B &nts::HEF4001B::operator=(nts::HEF4001B const &toCopy)
{
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