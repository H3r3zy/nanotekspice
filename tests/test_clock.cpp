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

	cr_assert_eq(component.compute(), nts::FALSE, "Assert1: expected 0");
	component.setValue(nts::TRUE);
	cr_assert_eq(component.compute(), nts::TRUE, "Assert2: expected 1");
	component.setValue(nts::UNDEFINED);
	cr_assert_eq(component.compute(), nts::UNDEFINED, "Assert3: expected -1");
	component();
	cr_assert_eq(component.compute(), nts::UNDEFINED, "Assert4: expected -1");
	component.setValue(nts::TRUE);
	component();
	cr_assert_eq(component.compute(), nts::FALSE, "Assert5: expected 0");
	component();
	cr_assert_eq(component.compute(), nts::TRUE, "Assert6: expected 1");
}