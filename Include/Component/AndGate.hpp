/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_ANDGATE_HPP
#define CPP_NANOTEKSPICE_ANDGATE_HPP

#include <iostream>
#include <map>
#include "AbstractComponent.hpp"

namespace nts {

	class AndGate : public nts::AbstractComponent {
	public:
		// Constructor
		AndGate() = default;

		AndGate(nts::AndGate const &);

		// Destructor
		~AndGate() override = default;

		// Operator
		nts::AndGate &operator=(nts::AndGate const &);


		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::AndGate *copy() const override;
	};
}

#endif //CPP_NANOTEKSPICE_ANDGATE_HPP
