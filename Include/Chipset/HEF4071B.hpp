/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_HEF4071B_HPP
#define CPP_NANOTEKSPICE_HEF4071B_HPP

#include <iostream>
#include "OrGate.hpp"
#include "AbstractComponent.hpp"

namespace nts {
	class HEF4071B: public AbstractComponent {
		public:
		// Constructor
		HEF4071B();

		HEF4071B(nts::HEF4071B const &);

		// Destructor
		~HEF4071B() override;

		// Operator
		HEF4071B &operator=(nts::HEF4071B const &);

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

std::ostream &operator<<(std::ostream &os, nts::HEF4071B const &);

#endif //CPP_NANOTEKSPICE_HEF4071B_HPP
