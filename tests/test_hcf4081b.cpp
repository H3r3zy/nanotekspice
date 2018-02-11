/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "HCF4081B.hpp"
#include "Input.hpp"

Test(HCF4081B, TruthTable, .init = cr_redirect_stdout)
{
	nts::HCF4081B hcf4081b;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	hcf4081b.setLink(1, iFalse, 1);
	hcf4081b.setLink(2, iFalse, 1);
	hcf4081b.setLink(5, iFalse, 1);
	hcf4081b.setLink(6, iTrue, 1);
	hcf4081b.setLink(8, iTrue, 1);
	hcf4081b.setLink(9, iFalse, 1);
	hcf4081b.setLink(12, iTrue, 1);
	hcf4081b.setLink(13, iTrue, 1);

	cr_assert_eq(hcf4081b.compute(3), nts::FALSE, "Assert1: expected False");
	cr_assert_eq(hcf4081b.compute(4), nts::FALSE, "Assert2: expected False");
	cr_assert_eq(hcf4081b.compute(10), nts::FALSE,
		"Assert3: expected False");
	cr_assert_eq(hcf4081b.compute(11), nts::TRUE,
		"Assert4: expected True");
}