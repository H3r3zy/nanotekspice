/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_NORGATE_HPP
#define CPP_NANOTEKSPICE_NORGATE_HPP

#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {
	class NorGate : public nts::AbstractComponent {
	public:
		// Constructor
		NorGate() = default;

		NorGate(nts::NorGate const &);

		// Destructor
		~NorGate() = default;

		// Operator
		NorGate &operator=(nts::NorGate const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;

	protected:

	private:

	};
}

std::ostream &operator<<(std::ostream &os, nts::NorGate const &);

#endif //CPP_NANOTEKSPICE_NORGATE_HPP
