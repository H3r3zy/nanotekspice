/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CD4094BC_HPP
#define CPP_NANOTEKSPICE_CD4094BC_HPP

#include <vector>
#include "AbstractComponent.hpp"

namespace nts {
	class CD4094BC: public AbstractComponent {
		public:
		// Constructor
		CD4094BC();
		CD4094BC(nts::CD4094BC const &data);

		// Destructor
		~CD4094BC() override = default;

		// Operator
		nts::CD4094BC &operator=(nts::CD4094BC const &data);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::CD4094BC *copy() const override;
		void reset() override;
	private:
		nts::Tristate lastClock = nts::UNDEFINED;
		nts::Tristate tmp = nts::UNDEFINED;


		bool first = true;

		std::vector<nts::Tristate> _data = {nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE};
	};
}

#endif //CPP_NANOTEKSPICE_CD4094BC_HPP
