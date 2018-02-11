/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_HEF4001B_HPP
#define CPP_NANOTEKSPICE_HEF4001B_HPP

#include <iostream>
#include "NorGate.hpp"
#include "AbstractComponent.hpp"

namespace nts {
	class HEF4001B: public AbstractComponent {
	public:
		// Constructor
		HEF4001B();

		HEF4001B(nts::HEF4001B const &);

		// Destructor
		~HEF4001B() override;

		// Operator
		HEF4001B &operator=(nts::HEF4001B const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin = 3) override;
		void dump() const override;

	protected:

	private:
		nts::IComponent *gate1;
		nts::IComponent *gate2;
		nts::IComponent *gate3;
		nts::IComponent *gate4;
	};
}

std::ostream &operator<<(std::ostream &os, nts::HEF4001B const &);

#endif //CPP_NANOTEKSPICE_HEF4001B_HPP
