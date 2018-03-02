/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <csignal>
#include <cstdarg>
#include "Executor.hpp"
#include "Parsing.hpp"

template<typename Func, typename Key>
void Executor<Func, Key>::add(Key const &key, Func func)
{
	executor[key] = func;
}

template<typename Func, typename Key>
void Executor<Func, Key>::execute(Key const &key)
{
	if (ISINMAP(key, executor)) {
		executor[key]();
	} else {
		throw std::out_of_range("Command not found");
	}
}

template class Executor<std::function<void (void)>, std::string>;