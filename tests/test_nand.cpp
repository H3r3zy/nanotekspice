/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "NandGate.hpp"
#include "Input.hpp"

Test(NandGate, TruthTable, .init = cr_redirect_stdout)
{
	nts::NandGate nandGate;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;
	nts::Tristate res;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	nandGate.setLink(1, iFalse, 1);
	nandGate.setLink(2, iFalse, 1);
	cr_assert_eq(nandGate.compute(), nts::TRUE, "Assert1: expected True");

	nandGate.setLink(1, iTrue, 1);
	nandGate.setLink(2, iFalse, 1);
	cr_assert_eq(nandGate.compute(), nts::TRUE, "Assert2: expected True");

	nandGate.setLink(1, iFalse, 1);
	nandGate.setLink(2, iTrue, 1);
	cr_assert_eq(nandGate.compute(), nts::TRUE, "Assert3: expected True");

	nandGate.setLink(1, iTrue, 1);
	nandGate.setLink(2, iTrue, 1);
	cr_assert_eq(nandGate.compute(), nts::FALSE, "Assert4: expected False");

	nandGate.setLink(1, iUndefined, 1);
	nandGate.setLink(2, iFalse, 1);
	cr_assert_eq(nandGate.compute(), nts::TRUE, "Assert5: expected True");

	nandGate.setLink(1, iFalse, 1);
	nandGate.setLink(2, iUndefined, 1);
	cr_assert_eq(nandGate.compute(), nts::TRUE, "Assert6: expected True");

	nandGate.setLink(1, iUndefined, 1);
	nandGate.setLink(2, iTrue, 1);
	cr_assert_eq(nandGate.compute(), nts::UNDEFINED, "Assert7: expected Undefined");

	nandGate.setLink(1, iTrue, 1);
	nandGate.setLink(2, iUndefined, 1);
	cr_assert_eq(nandGate.compute(), nts::UNDEFINED, "Assert8: expected Undefined");

	nandGate.setLink(1, iUndefined, 1);
	nandGate.setLink(2, iUndefined, 1);
	cr_assert_eq(nandGate.compute(), nts::UNDEFINED, "Assert9: expected Undefined");
}
