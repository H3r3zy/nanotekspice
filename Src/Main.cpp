/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by quentin.le-bars@epitech.eu,
*/

#include <algorithm>
#include <functional>
#include <csignal>
#include "Parsing2.hpp"
#include "ErrorParsing.hpp"
#include "Executor.hpp"
#include "Interpretor.hpp"

int main(int ac, char **av)
{
	if (ac == 1) {
		std::cout
			<< "./nanotekspice circuit_file.nts input_name="
				"input_value" << std::endl;
		return (0);
	}
	try {
		nts::Parsing P(*new std::string(av[1]), av);
		Interpretor interpretor(P);
		interpretor.run();
	} catch (nts::errorParsing const &message) {
		std::cerr << message.getMessage() << message.getIndication()
			<< std::endl;
		return (1);
	} catch (std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	// take argument
	return (0);
}