/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_OUTPUT_HPP
#define CPP_NANOTEKSPICE_OUTPUT_HPP

#include <iostream>
#include <AbstractComponent.hpp>

namespace nts {

	class Output : public nts::AbstractComponent {
	public:
		// Constructor
		Output();

		Output(nts::Output const &);

		// Destructor
		~Output() = default;

		// Operator
		nts::Output &operator=(nts::Output const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::Output *copy() const override;
	protected:

	private:
	};
}

std::ostream &operator<<(std::ostream &os, nts::Output const &);

#endif //CPP_NANOTEKSPICE_OUTPUT_HPP
