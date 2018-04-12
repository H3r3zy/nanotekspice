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
	cr_assert_eq(nandGate.compute(3), nts::TRUE, "Assert1: expected True");

	nandGate.setLink(1, iTrue, 1);
	nandGate.setLink(2, iFalse, 1);
	cr_assert_eq(nandGate.compute(3), nts::TRUE, "Assert2: expected True");

	nandGate.setLink(1, iFalse, 1);
	nandGate.setLink(2, iTrue, 1);
	cr_assert_eq(nandGate.compute(3), nts::TRUE, "Assert3: expected True");

	nandGate.setLink(1, iTrue, 1);
	nandGate.setLink(2, iTrue, 1);
	cr_assert_eq(nandGate.compute(3), nts::FALSE, "Assert4: expected False");

	nandGate.setLink(1, iUndefined, 1);
	nandGate.setLink(2, iFalse, 1);
	cr_assert_eq(nandGate.compute(3), nts::TRUE, "Assert5: expected True");

	nandGate.setLink(1, iFalse, 1);
	nandGate.setLink(2, iUndefined, 1);
	cr_assert_eq(nandGate.compute(3), nts::TRUE, "Assert6: expected True");

	nandGate.setLink(1, iUndefined, 1);
	nandGate.setLink(2, iTrue, 1);
	cr_assert_eq(nandGate.compute(3), nts::UNDEFINED, "Assert7: expected Undefined");

	nandGate.setLink(1, iTrue, 1);
	nandGate.setLink(2, iUndefined, 1);
	cr_assert_eq(nandGate.compute(3), nts::UNDEFINED, "Assert8: expected Undefined");

	nandGate.setLink(1, iUndefined, 1);
	nandGate.setLink(2, iUndefined, 1);
	cr_assert_eq(nandGate.compute(3), nts::UNDEFINED, "Assert9: expected Undefined");
}


Test(NandGate, dump, .init = cr_redirect_stdout)
{
nts::NandGate gate;
gate.dump();

cr_assert_stdout_eq_str("Nand Gate\n", "Dump error");
}

Test(NandGate, copy, .init = cr_redirect_stdout)
{
auto c1 = new nts::NandGate();
auto c2 = c1->copy();

cr_assert_neq(c1, c2);

delete c1;
delete c2;
}

Test(NandGate, equalConstructor, .init = cr_redirect_stdout)
{
nts::NandGate c1;
nts::NandGate c2;
c2 = c1;
cr_assert_neq(&c1, &c2);
}