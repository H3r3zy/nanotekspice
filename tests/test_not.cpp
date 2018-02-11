/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "NotGate.hpp"
#include "Input.hpp"

Test(NotGate, TruthTable, .init = cr_redirect_stdout)
{
	nts::NotGate notGate;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	notGate.setLink(1, iFalse, 1);
	cr_assert_eq(notGate.compute(), nts::TRUE, "Assert1: expected True");

	notGate.setLink(1, iTrue, 1);
	cr_assert_eq(notGate.compute(), nts::FALSE, "Assert2: expected False");

	notGate.setLink(1, iUndefined, 1);
	cr_assert_eq(notGate.compute(), nts::UNDEFINED, "Assert3: expected Undefined");
}