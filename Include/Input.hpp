/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_INPUT_HPP
#define CPP_NANOTEKSPICE_INPUT_HPP

#include <iostream>
#include "IComponent.hpp"
#include "AbstractComponent.hpp"

namespace nts {
	class Input: public nts::AbstractComponent {
	public:
		// Constructor
		Input() = default;

		Input(nts::Input const &);

		// Destructor
		~Input() override = default;

		// Operator
		nts::Input &operator=(nts::Input const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void setValue(nts::Tristate = nts::UNDEFINED);
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) override;

		void dump() const override;
		nts::Input *copy() const override;

	protected:
		nts::Tristate _value = nts::UNDEFINED;
	private:
	};
}

std::ostream &operator<<(std::ostream &os, nts::Input const &);

#endif //CPP_NANOTEKSPICE_INPUT_HPP
