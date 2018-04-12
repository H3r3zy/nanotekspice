/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "CD4030C.hpp"
#include "Input.hpp"

Test(CD4030C, TruthTable, .init = cr_redirect_stdout)
{
	nts::CD4030C cd4030c;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	cd4030c.setLink(1, iFalse, 1);
	cd4030c.setLink(2, iFalse, 1);
	cd4030c.setLink(5, iFalse, 1);
	cd4030c.setLink(6, iTrue, 1);
	cd4030c.setLink(8, iTrue, 1);
	cd4030c.setLink(9, iFalse, 1);
	cd4030c.setLink(12, iTrue, 1);
	cd4030c.setLink(13, iTrue, 1);

	cr_assert_eq(cd4030c.compute(3), nts::FALSE, "Assert1: expected False");
	cr_assert_eq(cd4030c.compute(4), nts::TRUE, "Assert2: expected True");
	cr_assert_eq(cd4030c.compute(10), nts::TRUE,
		"Assert3: expected True");
	cr_assert_eq(cd4030c.compute(11), nts::FALSE,
		"Assert4: expected False");
}


Test(CD4030C, dump, .init = cr_redirect_stdout)
{
nts::CD4030C gate;
gate.dump();

cr_assert_stdout_eq_str("CD4030C Chipset\n", "Dump error");
}

Test(CD4030C, copy, .init = cr_redirect_stdout)
{
nts::CD4030C *c1 = new nts::CD4030C();
auto c2 = c1->copy();

cr_assert_neq(c1, c2);

delete c1;
delete c2;
}

Test(CD4030C, equalConstructor, .init = cr_redirect_stdout)
{
nts::CD4030C c1;
nts::CD4030C c2;
c2 = c1;
cr_assert_neq(&c1, &c2);
}