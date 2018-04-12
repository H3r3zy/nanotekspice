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
		nts::FullAdderComponent &operator=(nts::FullAdderComponent const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::FullAdderComponent *copy() const override;

		protected:

		private:

	};
}

#endif //CPP_NANOTEKSPICE_FULLADDERCOMPONENT_HPP
