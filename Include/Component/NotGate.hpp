/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_NOTGATE_HPP
#define CPP_NANOTEKSPICE_NOTGATE_HPP

#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {

	class NotGate : public nts::AbstractComponent {
		public:
		// Constructor
		NotGate();

		NotGate(nts::NotGate const &);

		// Destructor
		~NotGate() override = default;

		// Operator
		NotGate &operator=(nts::NotGate const &);

		// Other
		nts::Tristate compute(std::size_t pin = 2) override;
		void dump() const override;
	};
}

std::ostream &operator<<(std::ostream &os, nts::NotGate const &);

#endif //CPP_NANOTEKSPICE_NOTGATE_HPP
