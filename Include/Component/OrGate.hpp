/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_ORGATE_HPP
#define CPP_NANOTEKSPICE_ORGATE_HPP

#include <iostream>
#include <map>
#include "AbstractComponent.hpp"

namespace nts {

	class OrGate : public nts::AbstractComponent {
	public:
		// Constructor
		OrGate() = default;

		OrGate(nts::OrGate const &);

		// Destructor
		~OrGate() override = default;

		// Operator
		nts::OrGate &operator=(nts::OrGate const &);

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::OrGate *copy() const override;

	};
}

#endif //CPP_NANOTEKSPICE_ORGATE_HPP
