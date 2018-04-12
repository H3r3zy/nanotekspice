/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_MC14040B_HPP
#define CPP_NANOTEKSPICE_MC14040B_HPP

#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {
	class MC14040B: public AbstractComponent {
	public:
		// Constructor
		MC14040B();

		MC14040B(nts::MC14040B const &);

		// Destructor
		~MC14040B() = default;

		// Operator
		nts::MC14040B &operator=(nts::MC14040B const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::MC14040B *copy() const override;
		void reset() override;
	protected:

	private:
		unsigned int _counter = 0;
		nts::Tristate lastClock = nts::UNDEFINED;
		nts::Tristate tmp = nts::UNDEFINED;
		bool first = true;
	};
}

#endif //CPP_NANOTEKSPICE_MC14040B_HPP
