/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Clock.hpp"

Test(Clock, TruthTable, .init = cr_redirect_stdout)
{
	nts::Clock component;

	cr_assert_eq(component.compute(1), nts::FALSE, "Assert1: expected 0");
	component.setValue(nts::TRUE);
	cr_assert_eq(component.compute(1), nts::TRUE, "Assert2: expected 1");
	component.setValue(nts::UNDEFINED);
	cr_assert_eq(component.compute(1), nts::UNDEFINED, "Assert3: expected -1");
	component();
	cr_assert_eq(component.compute(1), nts::UNDEFINED, "Assert4: expected -1");
	component.setValue(nts::TRUE);
	component();
	cr_assert_eq(component.compute(1), nts::FALSE, "Assert5: expected 0");
	component();
	cr_assert_eq(component.compute(1), nts::TRUE, "Assert6: expected 1");
}


Test(Clock, dump, .init = cr_redirect_stdout)
{
nts::Clock gate;
gate.dump();

cr_assert_stdout_eq_str("Clock: 0\n", "Dump error");
}

Test(Clock, copy, .init = cr_redirect_stdout)
{
auto c1 = new nts::Clock();
auto c2 = c1->copy();

cr_assert_neq(c1, c2);

delete c1;
delete c2;
}

Test(Clock, equalConstructor, .init = cr_redirect_stdout)
{
nts::Clock c1;
nts::Clock c2;
c2 = c1;
cr_assert_neq(&c1, &c2);
}