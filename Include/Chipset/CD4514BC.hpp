/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_CD4514BC_HPP
#define CPP_NANOTEKSPICE_CD4514BC_HPP


#include <iostream>
#include "AbstractComponent.hpp"

namespace nts {
	class CD4514BC: public AbstractComponent {
	public:
		// Constructor
		CD4514BC();

		CD4514BC(nts::CD4514BC const &);

		// Destructor
		~CD4514BC() override = default;

		// Operator
		nts::CD4514BC &operator=(nts::CD4514BC const &);

		// Getter

		// Setter

		// Other
		nts::Tristate compute(std::size_t pin) override;
		void dump() const override;
		nts::CD4514BC *copy() const override;

	protected:

	private:
		std::map<std::string, std::string> truth = {
			{"0000", "1000000000000000"},
			{"0001", "0100000000000000"},
			{"0010", "0010000000000000"},
			{"0011", "0001000000000000"},
			{"0100", "0000100000000000"},
			{"0101", "0000010000000000"},
			{"0110", "0000001000000000"},
			{"0111", "0000000100000000"},
			{"1000", "0000000010000000"},
			{"1001", "0000000001000000"},
			{"1010", "0000000000100000"},
			{"1011", "0000000000010000"},
			{"1100", "0000000000001000"},
			{"1101", "0000000000000100"},
			{"1110", "0000000000000010"},
			{"1111", "0000000000000001"},
			{"000U", "UU00000000000000"},
			{"00U0", "U0U0000000000000"},
			{"0U00", "U000U00000000000"},
			{"U000", "U0000000U0000000"},
			{"00UU", "UUUU000000000000"},
			{"0UU0", "U0U0U0U000000000"},
			{"UU00", "U000U000U000U000"},
			{"U00U", "UU000000UU000000"},
			{"0U0U", "UU00UU0000000000"},
			{"U0U0", "U0U00000U0U00000"},
			{"0UUU", "UUUUUUUU00000000"},
			{"UUU0", "U0U0U0U0U0U0U0U0"},
			{"UU0U", "UU00UU00UU00UU00"},
			{"U0UU", "UUUU0000UUUU0000"},
			{"111U", "00000000000000UU"},
			{"11U1", "0000000000000U0U"},
			{"1U11", "00000000000U000U"},
			{"U111", "0000000U0000000U"},
			{"11UU", "000000000000UUUU"},
			{"1UU1", "000000000U0U0U0U"},
			{"UU11", "000U000U000U000U"},
			{"U11U", "000000UU000000UU"},
			{"1U1U", "0000000000UU00UU"},
			{"U1U1", "00000U0U00000U0U"},
			{"1UUU", "00000000UUUUUUUU"},
			{"UUU1", "0U0U0U0U0U0U0U0U"},
			{"UU1U", "00UU00UU00UU00UU"},
			{"U1UU", "0000UUUU0000UUUU"},
			{"UUUU", "UUUUUUUUUUUUUUUU"}
		};
	};
}

std::ostream &operator<<(std::ostream &os, nts::CD4514BC const &);

#endif //CPP_NANOTEKSPICE_CD4514BC_HPP
