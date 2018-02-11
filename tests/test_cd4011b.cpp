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