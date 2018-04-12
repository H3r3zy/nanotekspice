/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_ABSTRACTCOMPONENT_HPP
#define CPP_NANOTEKSPICE_ABSTRACTCOMPONENT_HPP

#include <iostream>
#include <map>
#include "IComponent.hpp"

namespace nts {
	class AbstractComponent: public nts::IComponent {
	public:
		// Constructor

		// Destructor
		virtual ~AbstractComponent() = default;

		// Operator

		// Getter
		virtual nts::Tristate getPins(size_t pin);

		// Setter
		virtual void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);

		// Other
		virtual nts::Tristate compute(std::size_t pin) = 0;

		virtual void dump() const = 0;
		void reset();

	protected:
		nts::Tristate _res = nts::UNDEFINED;
		std::size_t _pin_number = 3;
		std::map<long unsigned int, nts::IComponent *> _pins;
		std::map<long unsigned int, std::size_t> _pinsArgument;

		std::string &tristate2Value(nts::Tristate tristate) const;
		nts::Tristate value2Tristate(std::string &value) const;
		nts::Tristate value2Tristate(char value) const;

		unsigned int _maxUsePerCycle = 8000;
		unsigned int cycle = 0;
	private:

	};
}

std::ostream &operator<<(std::ostream &os, nts::AbstractComponent const &);

#endif //CPP_NANOTEKSPICE_ABSTRACTCOMPONENT_HPP
