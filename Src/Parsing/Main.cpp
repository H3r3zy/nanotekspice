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
		std::map<std::string, nts::IComponent *> components = P.getComponents();
		std::map<std::string, nts::Input *> inputs = P.getInputs();
		std::map<std::string, nts::Output *> outputs = P.getOutputs();
		std::map<std::string, nts::Clock *> clocks = P.getClocks();

		for (auto it = outputs.begin(); it != outputs.end(); it++) {
			std::cout << it->first << ": ";
			std::cout << it->second->compute(1) << std::endl;

		}
	} catch (nts::ErrorParsing const &message) {
		std::cout << message.GetMessage() << message.GetIndication()
			<< std::endl;
		return (1);
	}
	// take argument
	return (0);
}