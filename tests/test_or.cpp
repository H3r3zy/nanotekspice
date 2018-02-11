/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "OrGate.hpp"
#include "Input.hpp"

Test(OrGate, TruthTable, .init = cr_redirect_stdout)
{
	nts::OrGate orGate;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;
	nts::Tristate res;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	orGate.setLink(1, iFalse, 1);
	orGate.setLink(2, iFalse, 1);
	cr_assert_eq(orGate.compute(), nts::FALSE, "Assert1: expected False");

	orGate.setLink(1, iTrue, 1);
	orGate.setLink(2, iFalse, 1);
	cr_assert_eq(orGate.compute(), nts::TRUE, "Assert2: expected True");

	orGate.setLink(1, iFalse, 1);
	orGate.setLink(2, iTrue, 1);
	cr_assert_eq(orGate.compute(), nts::TRUE, "Assert3: expected True");

	orGate.setLink(1, iTrue, 1);
	orGate.setLink(2, iTrue, 1);
	cr_assert_eq(orGate.compute(), nts::TRUE, "Assert4: expected True");

	orGate.setLink(1, iUndefined, 1);
	orGate.setLink(2, iFalse, 1);
	cr_assert_eq(orGate.compute(), nts::UNDEFINED, "Assert5: expected Undefined");

	orGate.setLink(1, iFalse, 1);
	orGate.setLink(2, iUndefined, 1);
	cr_assert_eq(orGate.compute(), nts::UNDEFINED, "Assert6: expected Undefined");

	orGate.setLink(1, iUndefined, 1);
	orGate.setLink(2, iTrue, 1);
	cr_assert_eq(orGate.compute(), nts::TRUE, "Assert7: expected True");

	orGate.setLink(1, iTrue, 1);
	orGate.setLink(2, iUndefined, 1);
	cr_assert_eq(orGate.compute(), nts::TRUE, "Assert8: expected True");

	orGate.setLink(1, iUndefined, 1);
	orGate.setLink(2, iUndefined, 1);
	cr_assert_eq(orGate.compute(), nts::UNDEFINED, "Assert9: expected Undefined");
}