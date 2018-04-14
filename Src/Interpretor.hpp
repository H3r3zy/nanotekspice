/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_INTERPRETOR_HPP
#define CPP_NANOTEKSPICE_INTERPRETOR_HPP

#include <iostream>
#include <map>
#include "Executor.hpp"
#include "IComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "Parsing2.hpp"

class Interpretor {
public:
	// Constructor
	explicit Interpretor(nts::Parsing &parser);

	// Destructor
	~Interpretor() = default;

	// Operator

	// Getter

	// Setter

	// Other
	static void sig_handler(int sig);
	static bool loopStatus(bool status, bool setter);
	void run();
	void changeValue(std::map<std::string, nts::Input *> &inputs,
		std::string const &name, std::string const &value);
protected:

private:
	bool end = false;
	bool loop = false;

	std::map<std::string, nts::IComponent *> components;
	std::map<std::string, nts::Input *> inputs;
	std::map<std::string, nts::Output *> outputs;
	std::map<std::string, nts::Clock *> clocks;

	Executor<> exec;
};

#endif //CPP_NANOTEKSPICE_INTERPRETOR_HPP
