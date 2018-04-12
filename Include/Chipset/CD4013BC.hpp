/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CD4013BC_HPP
#define CPP_NANOTEKSPICE_CD4013BC_HPP

#include "AbstractComponent.hpp"

namespace nts {
	class CD4013BC: public AbstractComponent {
	public:
		// Constructor
		CD4013BC();
		CD4013BC(nts::CD4013BC const &);

		// Destructor
		~CD4013BC() override = default;

		// Operator
		nts::CD4013BC &operator=(nts::CD4013BC const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::CD4013BC *copy() const override;
		void reset() override;

	private:
		nts::Tristate lastClock1 = nts::UNDEFINED;
		nts::Tristate lastClock2 = nts::UNDEFINED;

		nts::Tristate tmp1 = nts::UNDEFINED;
		nts::Tristate tmp2 = nts::UNDEFINED;

		bool first = true;

		nts::Tristate saveQ1 = nts::UNDEFINED;
		nts::Tristate saveNQ1 = nts::UNDEFINED;

		nts::Tristate saveQ2 = nts::UNDEFINED;
		nts::Tristate saveNQ2 = nts::UNDEFINED;
	};
}

#endif //CPP_NANOTEKSPICE_CD4013BC_HPP
