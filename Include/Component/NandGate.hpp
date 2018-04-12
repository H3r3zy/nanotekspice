/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_NANDGATE_HPP
#define CPP_NANOTEKSPICE_NANDGATE_HPP

#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {
	class NandGate : public nts::AbstractComponent {
	public:
		// Constructor
		NandGate() = default;

		NandGate(nts::NandGate const &);

		// Destructor
		~NandGate() override = default;

		// Operator
		nts::NandGate &operator=(nts::NandGate const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::NandGate *copy() const override;

	protected:

	private:

	};
}

#endif //CPP_NANOTEKSPICE_NANDGATE_HPP
