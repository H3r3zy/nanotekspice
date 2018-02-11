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
		XorGate();

		XorGate(nts::XorGate const &);

		// Destructor
		~XorGate() = default;

		// Operator
		XorGate &operator=(nts::XorGate const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin = 3) override;
		void dump() const override;

		protected:

		private:

	};
}

std::ostream &operator<<(std::ostream &os, nts::XorGate const &);

#endif //CPP_NANOTEKSPICE_XORGATE_HPP
