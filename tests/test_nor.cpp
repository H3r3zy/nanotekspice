/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "NorGate.hpp"
#include "Input.hpp"

Test(NorGate, TruthTable, .init = cr_redirect_stdout)
{
	nts::NorGate norGate;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;
	nts::Tristate res;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	norGate.setLink(1, iFalse, 1);
	norGate.setLink(2, iFalse, 1);
	cr_assert_eq(norGate.compute(), nts::TRUE, "Assert1: expected True");

	norGate.setLink(1, iTrue, 1);
	norGate.setLink(2, iFalse, 1);
	cr_assert_eq(norGate.compute(), nts::FALSE, "Assert2: expected False");

	norGate.setLink(1, iFalse, 1);
	norGate.setLink(2, iTrue, 1);
	cr_assert_eq(norGate.compute(), nts::FALSE, "Assert3: expected False");

	norGate.setLink(1, iTrue, 1);
	norGate.setLink(2, iTrue, 1);
	cr_assert_eq(norGate.compute(), nts::FALSE, "Assert4: expected False");

	norGate.setLink(1, iUndefined, 1);
	norGate.setLink(2, iFalse, 1);
	cr_assert_eq(norGate.compute(), nts::UNDEFINED, "Assert5: expected Undefined");

	norGate.setLink(1, iFalse, 1);
	norGate.setLink(2, iUndefined, 1);
	cr_assert_eq(norGate.compute(), nts::UNDEFINED, "Assert6: expected Undefined");

	norGate.setLink(1, iUndefined, 1);
	norGate.setLink(2, iTrue, 1);
	cr_assert_eq(norGate.compute(), nts::FALSE, "Assert7: expected False");

	norGate.setLink(1, iTrue, 1);
	norGate.setLink(2, iUndefined, 1);
	cr_assert_eq(norGate.compute(), nts::FALSE, "Assert8: expected False");

	norGate.setLink(1, iUndefined, 1);
	norGate.setLink(2, iUndefined, 1);
	cr_assert_eq(norGate.compute(), nts::UNDEFINED, "Assert9: expected Undefined");
}