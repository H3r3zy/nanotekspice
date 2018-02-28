/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CLOCK_HPP
#define CPP_NANOTEKSPICE_CLOCK_HPP

#include <iostream>
#include "Input.hpp"

namespace nts {
	class Clock: public nts::Input {
	public:
		// Constructor
		Clock();

		Clock(nts::Clock const &);

		// Destructor
		~Clock() = default;

		// Operator
		nts::Clock &operator=(nts::Clock const &);
		nts::Clock &operator()();

		// Getter

		// Setter

		// Other
		void dump() const;

	protected:

	private:
	};
}
std::ostream &operator<<(std::ostream &os, nts::Clock const &);


#endif //CPP_NANOTEKSPICE_CLOCK_HPP
