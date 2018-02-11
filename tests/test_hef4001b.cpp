/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "HEF4001B.hpp"
#include "Input.hpp"

Test(HEF4001B, TruthTable, .init = cr_redirect_stdout)
{
	nts::HEF4001B hef4001b;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	hef4001b.setLink(1, iFalse, 1);
	hef4001b.setLink(2, iFalse, 1);
	hef4001b.setLink(5, iFalse, 1);
	hef4001b.setLink(6, iTrue, 1);
	hef4001b.setLink(8, iTrue, 1);
	hef4001b.setLink(9, iFalse, 1);
	hef4001b.setLink(12, iTrue, 1);
	hef4001b.setLink(13, iTrue, 1);

	cr_assert_eq(hef4001b.compute(3), nts::TRUE, "Assert1: expected True");
	cr_assert_eq(hef4001b.compute(4), nts::FALSE, "Assert2: expected False");
	cr_assert_eq(hef4001b.compute(10), nts::FALSE,
		"Assert3: expected False");
	cr_assert_eq(hef4001b.compute(11), nts::FALSE,
		"Assert4: expected False");
}