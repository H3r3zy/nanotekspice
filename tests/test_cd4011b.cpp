/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "CD4011B.hpp"
#include "Input.hpp"

Test(CD4011B, TruthTable, .init = cr_redirect_stdout)
{
	nts::CD4011B cd4011b;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	cd4011b.setLink(1, iFalse, 1);
	cd4011b.setLink(2, iFalse, 1);
	cd4011b.setLink(5, iFalse, 1);
	cd4011b.setLink(6, iTrue, 1);
	cd4011b.setLink(8, iTrue, 1);
	cd4011b.setLink(9, iFalse, 1);
	cd4011b.setLink(12, iTrue, 1);
	cd4011b.setLink(13, iTrue, 1);

	cr_assert_eq(cd4011b.compute(3), nts::TRUE, "Assert1: expected True");
	cr_assert_eq(cd4011b.compute(4), nts::TRUE, "Assert2: expected True");
	cr_assert_eq(cd4011b.compute(10), nts::TRUE,
		"Assert3: expected True");
	cr_assert_eq(cd4011b.compute(11), nts::FALSE,
		"Assert4: expected False");
}


Test(CD4011B, dump, .init = cr_redirect_stdout)
{
nts::CD4011B gate;
gate.dump();

cr_assert_stdout_eq_str("CD4011B Chipset\n", "Dump error");
}

Test(CD4011B, copy, .init = cr_redirect_stdout)
{
nts::CD4011B *c1 = new nts::CD4011B();
auto c2 = c1->copy();

cr_assert_neq(c1, c2);

delete c1;
delete c2;
}

Test(CD4011B, equalConstructor, .init = cr_redirect_stdout)
{
nts::CD4011B c1;
nts::CD4011B c2;
c2 = c1;
cr_assert_neq(&c1, &c2);
}