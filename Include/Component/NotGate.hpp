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
		nts::NotGate &operator=(nts::NotGate const &);

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::NotGate *copy() const override;

	};
}

#endif //CPP_NANOTEKSPICE_NOTGATE_HPP
