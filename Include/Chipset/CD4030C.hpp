/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CD4030C_HPP
#define CPP_NANOTEKSPICE_CD4030C_HPP

#include <iostream>
#include "XorGate.hpp"
#include "AbstractComponent.hpp"

namespace nts {
	class CD4030C: public AbstractComponent {
	public:
		// Constructor
		CD4030C();

		CD4030C(nts::CD4030C const &);

		// Destructor
		~CD4030C() override;

		// Operator
		nts::CD4030C &operator=(nts::CD4030C const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::CD4030C *copy() const override;

	protected:

	private:
		nts::IComponent *gate1;
		nts::IComponent *gate2;
		nts::IComponent *gate3;
		nts::IComponent *gate4;
		void init();
	};
}

#endif //CPP_NANOTEKSPICE_CD4030C_HPP
