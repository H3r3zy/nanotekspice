/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_RSNORLATCHCOMPONENT_HPP
#define CPP_NANOTEKSPICE_RSNORLATCHCOMPONENT_HPP

#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {
	class RSNorLatchComponent: public AbstractComponent {
	public:
		// Constructor
		RSNorLatchComponent();

		RSNorLatchComponent(nts::RSNorLatchComponent const &);

		// Destructor
		~RSNorLatchComponent() override;

		// Operator
		nts::RSNorLatchComponent &operator=(nts::RSNorLatchComponent const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::RSNorLatchComponent *copy() const override;

	protected:

	private:
		nts::IComponent *_not;
		void init();
	};
}

#endif //CPP_NANOTEKSPICE_RSNORLATCHCOMPONENT_HPP
