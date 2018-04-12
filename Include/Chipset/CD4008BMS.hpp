/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CD4008BMS_HPP
#define CPP_NANOTEKSPICE_CD4008BMS_HPP

#include <iostream>
#include "FullAdderComponent.hpp"
#include "AbstractComponent.hpp"

namespace nts {
	class CD4008BMS: public AbstractComponent {
	public:
		// Constructor
		CD4008BMS();

		CD4008BMS(nts::CD4008BMS const &);

		// Destructor
		~CD4008BMS() override;

		// Operator
		nts::CD4008BMS &operator=(nts::CD4008BMS const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::CD4008BMS *copy() const override;

	protected:

	private:
		nts::IComponent *gate1;
		nts::IComponent *gate2;
		nts::IComponent *gate3;
		nts::IComponent *gate4;

		void init();
	};
}

#endif //CPP_NANOTEKSPICE_CD4008BMS_HPP
