/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "CD4069UBC.hpp"
#include "Input.hpp"

Test(CD4069UBC, TruthTable, .init = cr_redirect_stdout)
{
	nts::CD4069UBC cd4069ubc;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	cd4069ubc.setLink(1, iFalse, 1);
	cd4069ubc.setLink(3, iTrue, 1);
	cd4069ubc.setLink(5, iUndefined, 1);

	cr_assert_eq(cd4069ubc.compute(2), nts::TRUE,
		"Assert1: expected True");
	cr_assert_eq(cd4069ubc.compute(4), nts::FALSE,
		"Assert2: expected False");
	cr_assert_eq(cd4069ubc.compute(6), nts::UNDEFINED,
		"Assert3: expected Undefined");
}


Test(CD4069UBC, dump, .init = cr_redirect_stdout)
{
nts::CD4069UBC gate;
gate.dump();

cr_assert_stdout_eq_str("CD4069UBC Chipset\n", "Dump error");
}

Test(CD4069UBC, copy, .init = cr_redirect_stdout)
{
nts::CD4069UBC *c1 = new nts::CD4069UBC();
auto c2 = c1->copy();

cr_assert_neq(c1, c2);

delete c1;
delete c2;
}

Test(CD4069UBC, equalConstructor, .init = cr_redirect_stdout)
{
nts::CD4069UBC c1;
nts::CD4069UBC c2;
c2 = c1;
cr_assert_neq(&c1, &c2);
}