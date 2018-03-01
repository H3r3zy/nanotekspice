/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CLOCK_HPP
#define CPP_NANOTEKSPICE_CLOCK_HPP

#include <iostream>
#include "Input.hpp"

namespace nts {
	class Clock: public nts::AbstractComponent {
	public:
		// Constructor
		Clock();

		Clock(nts::Clock const &);

		// Destructor
		~Clock() = default;

		// Operator
		nts::Clock &operator=(nts::Clock const &);
		nts::Clock &operator()();

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void setValue(nts::Tristate = nts::UNDEFINED);
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;
		nts::Clock *copy() const override;

	protected:

	private:
		nts::Tristate _value = nts::UNDEFINED;
	};
}
std::ostream &operator<<(std::ostream &os, nts::Clock const &);


#endif //CPP_NANOTEKSPICE_CLOCK_HPP
