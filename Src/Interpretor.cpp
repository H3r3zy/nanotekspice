/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <csignal>
#include "Interpretor.hpp"

Interpretor::Interpretor(nts::Parsing &parser) :
	components(parser.getComponents()),
	inputs(parser.getInputs()),
	outputs(parser.getOutputs()),
	clocks(parser.getClocks())
{
	exec.add("simulate", ([this] {
		for (auto it: clocks) {
			(*it.second)();
		}
		for (auto it: outputs) {
			it.second->compute(1);
		}
	}));
	exec.add("dump", [this] {
		for (auto it: components) {
			std::cout << it.first << ": ";
			it.second->dump();
		}
	});
	exec.add("display", [this] {
		for (auto it:outputs) {
			nts::Tristate t = it.second->compute(1);
			std::cout << it.first << "=";
			if (t == nts::UNDEFINED)
				std::cout << "U" << std::endl;
			else
				std::cout << t << std::endl;
		}
	});
	exec.add("exit", [this] {
		end = true;
	});
	exec.add("loop", [this] {
		loop = true;
		Interpretor::loopStatus(true, true);
		std::signal(SIGINT, &Interpretor::sig_handler);
	});
}

void Interpretor::sig_handler(int sig)
{
	signal(sig, nullptr);
	Interpretor::loopStatus(false, true);
}

bool Interpretor::loopStatus(bool status, bool inhib)
{
	static bool st = false;

	if (inhib)
		st = status;
	return st;
}

void Interpretor::changeValue(std::map<std::string, nts::Input *> &inputs,
	std::string const &name, std::string const &value
)
{
	if (!ISINMAP(name, inputs)) {
		std::cerr << "Input " << name << " not found" << std::endl;
	} else if (std::string("01").find(value) == std::string::npos) {
		std::cerr << "Input value " << value << " not good" << std::endl;
	} else {
		if (value == "0")
			inputs[name]->setValue(nts::FALSE);
		else
			inputs[name]->setValue(nts::TRUE);
	}
}

void Interpretor::run()
{
	std::string line;
	exec.execute("display");
	while (!end) {
		loop = Interpretor::loopStatus(true, false);
		if (loop)
			line = "simulate";
		else {
			std::cout << ">";
			if (!std::getline(std::cin, line))
				end = true;
		}
		if (line.empty())
			continue;
		if (line.find('=') != std::string::npos) {
			changeValue(inputs, line.substr(0, line.find('=')), line.substr(line.find('=') + 1, -1));
			continue;
		}
		try {
			exec.execute(line);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}