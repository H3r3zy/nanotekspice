/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include "FullAdderComponent.hpp"

nts::FullAdderComponent::FullAdderComponent()
{
	_pin_number = 5;
}

nts::FullAdderComponent::FullAdderComponent(
	nts::FullAdderComponent const &toCopy
)
{
	(void) toCopy;
	delete this;
}

nts::FullAdderComponent &nts::FullAdderComponent::operator=(
	nts::FullAdderComponent const &toCopy
)
{
	(void) toCopy;
	delete this;
	return *this;
}

std::ostream &operator<<(std::ostream &os, nts::FullAdderComponent const &data)
{
	data.dump();
	return os;
}

nts::Tristate nts::FullAdderComponent::compute(size_t pin)
{
	if (pin == 4) {
		nts::Tristate value1 = getPins(1);
		nts::Tristate value2 = getPins(2);
		nts::Tristate value3 = getPins(3);
		int sum = VALUE(value1) + VALUE(value2) + VALUE(value3);
		int undefinedNumber =
			UNDEFINEDVALUE(value1) + UNDEFINEDVALUE(value2) +
				UNDEFINEDVALUE(value3);

		//std::cout << value1 << " " << value2 << " " << value3;
		if (sum >= 2) {
			_res = nts::TRUE;
		} else if (undefinedNumber >= 2 ||
			(undefinedNumber == 1 && sum == 1)) {
			_res = nts::UNDEFINED;
		} else {
			_res = nts::FALSE;
		}
	} else if (pin == 5) {
		nts::Tristate value1 = getPins(1);
		nts::Tristate value2 = getPins(2);
		nts::Tristate value3 = getPins(3);
		int sum = VALUE(value1) + VALUE(value2) + VALUE(value3);
		int undefinedNumber =
			UNDEFINEDVALUE(value1) + UNDEFINEDVALUE(value2) +
				UNDEFINEDVALUE(value3);

		if ((sum == 2 || sum == 0) && undefinedNumber == 0) {
			_res = nts::FALSE;
		} else if ((sum == 1 || sum == 3) && undefinedNumber == 0) {
			_res = nts::TRUE;
		} else {
			_res = nts::UNDEFINED;
		}
	} else {
		return getPins(pin);
	}
	return _res;
}

void nts::FullAdderComponent::dump() const
{
	std::cout << "Full Adder Component" << std::endl;
}