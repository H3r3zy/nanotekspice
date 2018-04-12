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
	init();
}

nts::RSNorLatchComponent::RSNorLatchComponent(nts::RSNorLatchComponent const &data)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	_not = new nts::NotGate(*(nts::NotGate *) data._not);
	init();
}

nts::RSNorLatchComponent& nts::RSNorLatchComponent::operator=(
	nts::RSNorLatchComponent const &data
)
{
	_pin_number = data._pin_number;
	_pinsArgument = data._pinsArgument;
	_pins = data._pins;
	_res = data._res;
	_not = data._not;
	_not = new nts::NotGate(*(nts::NotGate *) data._not);

	init();
	return *this;
}

nts::RSNorLatchComponent::~RSNorLatchComponent()
{
	delete _not;
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
	std::cout << "RSNorLatch Component" << std::endl;
}

nts::RSNorLatchComponent *nts::RSNorLatchComponent::copy() const
{
	return new nts::RSNorLatchComponent(*this);
}

void nts::RSNorLatchComponent::init()
{
	auto _this = dynamic_cast<nts::IComponent *>(this);

	_not->setLink(1, *this, 3);
	_this->setLink(4, *_not, 2);
}