/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/output.h>
#include <criterion/logging.h>
#include <criterion/stats.h>
#include "AndGate.hpp"
#include "Input.hpp"

Test(AndGate, TruthTable)
{
	nts::AndGate andGate;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;
	nts::Tristate res;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	andGate.setLink(1, iFalse, 1);
	andGate.setLink(2, iFalse, 1);
	cr_assert_eq(andGate.compute(), nts::FALSE, "Assert1: expected False");

	andGate.setLink(1, iTrue, 1);
	andGate.setLink(2, iFalse, 1);
	cr_assert_eq(andGate.compute(), nts::FALSE, "Assert2: expected False");

	andGate.setLink(1, iFalse, 1);
	andGate.setLink(2, iTrue, 1);
	cr_assert_eq(andGate.compute(), nts::FALSE, "Assert3: expected False");

	andGate.setLink(1, iTrue, 1);
	andGate.setLink(2, iTrue, 1);
	cr_assert_eq(andGate.compute(), nts::TRUE, "Assert4: expected True");

	andGate.setLink(1, iUndefined, 1);
	andGate.setLink(2, iFalse, 1);
	cr_assert_eq(andGate.compute(), nts::FALSE, "Assert5: expected False");

	andGate.setLink(1, iFalse, 1);
	andGate.setLink(2, iUndefined, 1);
	cr_assert_eq(andGate.compute(), nts::FALSE, "Assert6: expected False");

	andGate.setLink(1, iUndefined, 1);
	andGate.setLink(2, iTrue, 1);
	cr_assert_eq(andGate.compute(), nts::UNDEFINED, "Assert7: expected Undefined");

	andGate.setLink(1, iTrue, 1);
	andGate.setLink(2, iUndefined, 1);
	cr_assert_eq(andGate.compute(), nts::UNDEFINED, "Assert8: expected Undefined");

	andGate.setLink(1, iUndefined, 1);
	andGate.setLink(2, iUndefined, 1);
	cr_assert_eq(andGate.compute(), nts::UNDEFINED, "Assert9: expected Undefined");
}
