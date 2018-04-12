/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CD4069UBC_HPP
#define CPP_NANOTEKSPICE_CD4069UBC_HPP

#include <iostream>
#include "NotGate.hpp"
#include "AbstractComponent.hpp"

namespace nts {
	class CD4069UBC: public AbstractComponent {
	public:
		// Constructor
		CD4069UBC();

		CD4069UBC(nts::CD4069UBC const &);

		// Destructor
		~CD4069UBC() override;

		// Operator
		nts::CD4069UBC &operator=(nts::CD4069UBC const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::CD4069UBC *copy() const override;

	protected:

	private:
		nts::IComponent *gate1;
		nts::IComponent *gate2;
		nts::IComponent *gate3;
		nts::IComponent *gate4;
		nts::IComponent *gate5;
		nts::IComponent *gate6;
		void init();
	};
}

#endif //CPP_NANOTEKSPICE_CD4069UBC_HPP
