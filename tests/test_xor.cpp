/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "XorGate.hpp"
#include "Input.hpp"

Test(XorGate, TruthTable, .init = cr_redirect_stdout)
{
	nts::XorGate xorGate;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	xorGate.setLink(1, iFalse, 1);
	xorGate.setLink(2, iFalse, 1);
	cr_assert_eq(xorGate.compute(), nts::FALSE, "Assert1: expected False");

	xorGate.setLink(1, iTrue, 1);
	xorGate.setLink(2, iFalse, 1);
	cr_assert_eq(xorGate.compute(), nts::TRUE, "Assert2: expected True");

	xorGate.setLink(1, iFalse, 1);
	xorGate.setLink(2, iTrue, 1);
	cr_assert_eq(xorGate.compute(), nts::TRUE, "Assert3: expected True");

	xorGate.setLink(1, iTrue, 1);
	xorGate.setLink(2, iTrue, 1);
	cr_assert_eq(xorGate.compute(), nts::FALSE, "Assert4: expected False");

	xorGate.setLink(1, iUndefined, 1);
	xorGate.setLink(2, iFalse, 1);
	cr_assert_eq(xorGate.compute(), nts::UNDEFINED, "Assert5: expected Undefined");

	xorGate.setLink(1, iFalse, 1);
	xorGate.setLink(2, iUndefined, 1);
	cr_assert_eq(xorGate.compute(), nts::UNDEFINED, "Assert6: expected Undefined");

	xorGate.setLink(1, iUndefined, 1);
	xorGate.setLink(2, iTrue, 1);
	cr_assert_eq(xorGate.compute(), nts::UNDEFINED, "Assert7: expected Undefined");

	xorGate.setLink(1, iTrue, 1);
	xorGate.setLink(2, iUndefined, 1);
	cr_assert_eq(xorGate.compute(), nts::UNDEFINED, "Assert8: expected Undefined");

	xorGate.setLink(1, iUndefined, 1);
	xorGate.setLink(2, iUndefined, 1);
	cr_assert_eq(xorGate.compute(), nts::UNDEFINED, "Assert9: expected Undefined");
}