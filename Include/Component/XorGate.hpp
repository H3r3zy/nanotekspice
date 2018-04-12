/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_XORGATE_HPP
#define CPP_NANOTEKSPICE_XORGATE_HPP

#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {
	class XorGate : public nts::AbstractComponent {
	public:
		// Constructor
		XorGate() = default;

		XorGate(nts::XorGate const &);

		// Destructor
		~XorGate() = default;

		// Operator
		nts::XorGate &operator=(nts::XorGate const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::XorGate *copy() const  override;

	protected:

	private:

	};
}

#endif //CPP_NANOTEKSPICE_XORGATE_HPP
