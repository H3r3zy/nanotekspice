/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_ICOMPONENT_HPP
#define CPP_NANOTEKSPICE_ICOMPONENT_HPP

#include <cstddef>

namespace nts {
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IComponent {
	public:
		virtual ~IComponent() = default;

	public:
		virtual nts::Tristate compute(std::size_t pin = 1) = 0;

		virtual void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) = 0;

		virtual void dump() const = 0;
	};
}

#define ISUNDEFINED(x) 		(x) == nts::UNDEFINED
#define ISTRUE(x) 		(x) == nts::TRUE
#define ISFALSE(x) 		(x) == nts::FALSE

#define UNDEFINEDVALUE(x)	(((x) == nts::UNDEFINED) ? (1) : (0))
#define VALUE(x)		(((x) != nts::UNDEFINED) ? (x) : (0))

#endif //CPP_NANOTEKSPICE_ICOMPONENT_HPP
