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
	cr_assert_eq(norGate.compute(3), nts::TRUE, "Assert1: expected True");

	norGate.setLink(1, iTrue, 1);
	norGate.setLink(2, iFalse, 1);
	cr_assert_eq(norGate.compute(3), nts::FALSE, "Assert2: expected False");

	norGate.setLink(1, iFalse, 1);
	norGate.setLink(2, iTrue, 1);
	cr_assert_eq(norGate.compute(3), nts::FALSE, "Assert3: expected False");

	norGate.setLink(1, iTrue, 1);
	norGate.setLink(2, iTrue, 1);
	cr_assert_eq(norGate.compute(3), nts::FALSE, "Assert4: expected False");

	norGate.setLink(1, iUndefined, 1);
	norGate.setLink(2, iFalse, 1);
	cr_assert_eq(norGate.compute(3), nts::UNDEFINED, "Assert5: expected Undefined");

	norGate.setLink(1, iFalse, 1);
	norGate.setLink(2, iUndefined, 1);
	cr_assert_eq(norGate.compute(3), nts::UNDEFINED, "Assert6: expected Undefined");

	norGate.setLink(1, iUndefined, 1);
	norGate.setLink(2, iTrue, 1);
	cr_assert_eq(norGate.compute(3), nts::FALSE, "Assert7: expected False");

	norGate.setLink(1, iTrue, 1);
	norGate.setLink(2, iUndefined, 1);
	cr_assert_eq(norGate.compute(3), nts::FALSE, "Assert8: expected False");

	norGate.setLink(1, iUndefined, 1);
	norGate.setLink(2, iUndefined, 1);
	cr_assert_eq(norGate.compute(3), nts::UNDEFINED, "Assert9: expected Undefined");
}

Test(NorGate, dump, .init = cr_redirect_stdout)
{
nts::NorGate gate;
gate.dump();

cr_assert_stdout_eq_str("Nor Gate\n", "Dump error");
}

Test(NorGate, copy, .init = cr_redirect_stdout)
{
auto c1 = new nts::NorGate();
auto c2 = c1->copy();

cr_assert_neq(c1, c2);

delete c1;
delete c2;
}

Test(NorGate, equalConstructor, .init = cr_redirect_stdout)
{
nts::NorGate c1;
nts::NorGate c2;
c2 = c1;
cr_assert_neq(&c1, &c2);
}