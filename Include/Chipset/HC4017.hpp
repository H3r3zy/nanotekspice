/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_HC4017_HPP
#define CPP_NANOTEKSPICE_HC4017_HPP

#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {
	class HC4017: public AbstractComponent {
	public:
		// Constructor
		HC4017();

		HC4017(nts::HC4017 const &);

		// Destructor
		~HC4017() = default;

		// Operator
		nts::HC4017 &operator=(nts::HC4017 const &);

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::HC4017 *copy() const override;
		void reset() override;
	protected:

	private:
		unsigned int _counter = 1;
		nts::Tristate lastClock = nts::UNDEFINED;
		nts::Tristate tmp = nts::UNDEFINED;
		bool first = true;
	};
}

#endif //CPP_NANOTEKSPICE_HC4017_HPP
