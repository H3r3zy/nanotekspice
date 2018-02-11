/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <iostream>

ReportHook(POST_TEST)(struct criterion_test_stats *stats)
{
	printf("[%s] ", stats->test->category);
	printf("%s", stats->test->name);
	printf(" : %s\033[0m\n",
		(!stats->exit_code) ? "\033[32mOK" : "\033[31mKO");
}

ReportHook(POST_ALL)(struct criterion_global_stats *stats) {
	std::cout << std::endl << "Total Assertion: \033[32m" << stats->nb_asserts << "\033[0m" << std::endl;
}