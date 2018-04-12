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
		nts::NorGate &operator=(nts::NorGate const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::NorGate *copy() const override;

	protected:

	private:

	};
}

#endif //CPP_NANOTEKSPICE_NORGATE_HPP
