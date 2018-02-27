/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include "Parsing.hpp"
#include "ErrorParsing.hpp"

int main(int ac, char **av)
{
	if (ac == 1) {
		std::cout
			<< "./nanotekspice circuit_file.nts input_name="
				"input_value" << std::endl;
		return (1);
	}
	try {
		nts::Parsing P(av[1], ac, av);
	} catch (nts::ErrorParsing const &message) {
		std::cout << message.GetMessage() << message.GetIndication()
			<< std::endl;
	}
}