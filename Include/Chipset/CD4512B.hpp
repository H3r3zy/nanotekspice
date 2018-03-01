/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CD4512B_HPP
#define CPP_NANOTEKSPICE_CD4512B_HPP

#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {
	class CD4512B: public AbstractComponent {
	public:
		// Constructor
		CD4512B();

		CD4512B(nts::CD4512B const &);

		// Destructor
		~CD4512B() override = default;

		// Operator
		nts::CD4512B &operator=(nts::CD4512B const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::CD4512B *copy() const override;

	protected:
	private:

	};
}

std::ostream &operator<<(std::ostream &os, nts::CD4512B const &);

#endif //CPP_NANOTEKSPICE_CD4512B_HPP
