/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_FULLADDERCOMPONENT_HPP
#define CPP_NANOTEKSPICE_FULLADDERCOMPONENT_HPP

#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {
	class FullAdderComponent : public nts::AbstractComponent {
		public:
		// Constructor
		FullAdderComponent();

		FullAdderComponent(nts::FullAdderComponent const &);

		// Destructor
		~FullAdderComponent() = default;

		// Operator
		FullAdderComponent &operator=(nts::FullAdderComponent const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;

		protected:

		private:

	};
}

std::ostream &operator<<(std::ostream &os, nts::FullAdderComponent const &);

#endif //CPP_NANOTEKSPICE_FULLADDERCOMPONENT_HPP
