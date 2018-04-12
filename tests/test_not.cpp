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
	cr_assert_eq(notGate.compute(2), nts::TRUE, "Assert1: expected True");

	notGate.setLink(1, iTrue, 1);
	cr_assert_eq(notGate.compute(2), nts::FALSE, "Assert2: expected False");

	notGate.setLink(1, iUndefined, 1);
	cr_assert_eq(notGate.compute(2), nts::UNDEFINED, "Assert3: expected Undefined");
}

Test(NotGate, dump, .init = cr_redirect_stdout)
{
nts::NotGate gate;
gate.dump();

cr_assert_stdout_eq_str("Not Gate\n", "Dump error");
}

Test(NotGate, copy, .init = cr_redirect_stdout)
{
auto c1 = new nts::NotGate();
auto c2 = c1->copy();

cr_assert_neq(c1, c2);

delete c1;
delete c2;
}

Test(NotGate, equalConstructor)
{
nts::NotGate c1;
nts::NotGate c2;
c2 = c1;
cr_assert_neq(&c1, &c2);
}