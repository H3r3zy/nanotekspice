//
// Created by sahel on 11/04/18.
//

/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ErrorParsing.hpp"
#include "Parsing.hpp"
#include <unistd.h>
#include <exception>

Test(Parsing, test, .init = cr_redirect_stdout)
{
	auto av = (char **)malloc(sizeof(char *) * 9);
	av[0] = strdup("./nanotekspice");
	av[1] = strdup("SourceEpitech/01_basics/not.nts");
	av[2] = strdup("i0=1");
	av[3] = strdup("i1=1");
	av[4] = strdup("i2=1");
	av[5] = strdup("i3=1");
	av[6] = strdup("i4=1");
	av[7] = strdup("i5=1");
	av[8] = NULL;
	int ac = 8;


	cr_assert_no_throw(new nts::Parsing(*new std::string(av[1]), ac, av), std::exception);
	av[7] = NULL;

	cr_assert_throw(new nts::Parsing(*new std::string(av[1]), ac, av), std::exception);
	av[7] = strdup("i8=1");
	cr_assert_throw(new nts::Parsing(*new std::string(av[1]), ac, av), std::exception);
	av[7] = strdup("i5=2");
	cr_assert_throw(new nts::Parsing(*new std::string(av[1]), ac, av), std::exception);
	av[7] = strdup("i5");
	cr_assert_throw(new nts::Parsing(*new std::string(av[1]), ac, av), std::exception);
	av[7] = strdup("i5=1=2");
	cr_assert_throw(new nts::Parsing(*new std::string(av[1]), ac, av), std::exception);

	ac=2;
	cr_assert_throw(new nts::Parsing(*new std::string(av[1]), ac, av), std::exception);

	auto e = new nts::errorParsing("ici", "la");
	cr_assert_str_eq(e->getIndication().c_str(), "la");
	cr_assert_str_eq(e->getMessage().c_str(), "ici");

	ac = 8;
	av[7] = strdup("i5=1");
	auto p = new nts::Parsing(*new std::string(av[1]), ac, av);

	cr_assert_eq(p->getComponents().size(), 13);
	cr_assert_eq(p->getInputs().size(), 6);
	cr_assert_eq(p->getOutputs().size(), 6);
	cr_assert_eq(p->getClocks().size(), 0);

	av[1] = strdup("SourceEpitech/01_basics/not_error.nts");
	cr_assert_throw(new nts::Parsing(*new std::string(av[1]), ac, av), std::exception);

	delete p;
}
