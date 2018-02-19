/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/hooks.h>
#include <iostream>

ReportHook(POST_TEST)(struct criterion_test_stats *stats)
{
	printf("[%s] ", stats->test->category);
	printf("%s", stats->test->name);
	printf(" : %s\033[0m\n",
		(!stats->exit_code) ? "\033[32mOK" : "\033[31mKO");
}

ReportHook(POST_ALL)(struct criterion_global_stats *stats) {
	std::cout << std::endl;
	std::cout << "\033[0;37m[\033[34m====\033[0;37m] \033[1;37mAssertion: Tested: \033[0;34m" << stats->nb_asserts;
	std::cout << "\033[1;37m | Passing: \033[0;32m" << stats->asserts_passed;
	std::cout << "\033[1;37m | Failing: ";
	if (stats->asserts_failed)
		std::cout << "\33[0;31m" << stats->asserts_failed;
	else
		std::cout << "\033[0;0m" << stats->asserts_failed;
	std::cout << "\033[0;0m" << std::endl;
}

ReportHook(ASSERT)(struct criterion_assert_stats *stats) {
	std::cout << "[" << stats->file << "] " << stats->line << " : ";

	if (stats->passed) {
		std::cout << "\033[32mOK" << std::endl;
	} else {
		std::cout << "\033[31mKO \033[0m" << stats->message << std::endl;
	}
}