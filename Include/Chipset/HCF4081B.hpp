/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_HCF4081B_HPP
#define CPP_NANOTEKSPICE_HCF4081B_HPP

#include <iostream>
#include "AndGate.hpp"
#include "AbstractComponent.hpp"

namespace nts {
	class HCF4081B: public AbstractComponent {
	public:
		// Constructor
		HCF4081B();

		HCF4081B(nts::HCF4081B const &);

		// Destructor
		~HCF4081B() override;

		// Operator
		nts::HCF4081B &operator=(nts::HCF4081B const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::HCF4081B *copy() const override;

	protected:

	private:
		nts::IComponent *gate1;
		nts::IComponent *gate2;
		nts::IComponent *gate3;
		nts::IComponent *gate4;
		void init();
	};
}

#endif //CPP_NANOTEKSPICE_HCF4081B_HPP
