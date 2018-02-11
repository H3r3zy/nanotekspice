/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CD4011B_HPP
#define CPP_NANOTEKSPICE_CD4011B_HPP

#include <iostream>
#include "FullAdderComponent.hpp"
#include "AbstractComponent.hpp"

namespace nts {
	class CD4011B: public AbstractComponent {
		public:
		// Constructor
		CD4011B();

		CD4011B(nts::CD4011B const &);

		// Destructor
		~CD4011B() override;

		// Operator
		CD4011B &operator=(nts::CD4011B const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin = 3) override;
		void dump() const override;

		protected:

		private:
		nts::IComponent *gate1;
		nts::IComponent *gate2;
		nts::IComponent *gate3;
		nts::IComponent *gate4;
	};
}

std::ostream &operator<<(std::ostream &os, nts::CD4011B const &);


#endif //CPP_NANOTEKSPICE_CD4011B_HPP
