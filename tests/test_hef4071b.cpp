/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "HEF4071B.hpp"
#include "Input.hpp"

Test(HEF4071B, TruthTable, .init = cr_redirect_stdout)
{
	nts::HEF4071B hef4071b;
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	hef4071b.setLink(1, iFalse, 1);
	hef4071b.setLink(2, iFalse, 1);
	hef4071b.setLink(5, iFalse, 1);
	hef4071b.setLink(6, iTrue, 1);
	hef4071b.setLink(8, iTrue, 1);
	hef4071b.setLink(9, iFalse, 1);
	hef4071b.setLink(12, iTrue, 1);
	hef4071b.setLink(13, iTrue, 1);

	cr_assert_eq(hef4071b.compute(3), nts::FALSE, "Assert1: expected False");
	cr_assert_eq(hef4071b.compute(4), nts::TRUE, "Assert2: expected True");
	cr_assert_eq(hef4071b.compute(10), nts::TRUE,
		"Assert3: expected True");
	cr_assert_eq(hef4071b.compute(11), nts::TRUE,
		"Assert4: expected True");
}