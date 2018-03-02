/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_EXECUTOR_HPP
#define CPP_NANOTEKSPICE_EXECUTOR_HPP

#include <iostream>
#include <map>
#include <functional>
#include "IComponent.hpp"
#include "Input.hpp"
#include "Clock.hpp"
#include "Output.hpp"

template <typename Func = std::function<void (void)>,
	typename Key = std::string>
class Executor {
public:
	// Constructor
	Executor() = default;

	// Destructor
	~Executor() = default;

	// Operator

	// Getter

	// Setter

	// Other
	void add(Key const &key, Func func);
	void execute(Key const &key);

protected:

private:
	std::map<Key, Func> executor;
};


#endif //CPP_NANOTEKSPICE_EXECUTOR_HPP
