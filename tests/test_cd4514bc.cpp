/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <CD4514BC.hpp>
#include "Input.hpp"

static void testComponent(
	nts::IComponent &component,
	nts::Input &i0,
	nts::Input &i1,
	nts::Input &i2,
	nts::Input &i3,
	nts::Input &inhibit,
	nts::Tristate expected1,
	nts::Tristate expected2,
	nts::Tristate expected3,
	nts::Tristate expected4,
	nts::Tristate expected5,
	nts::Tristate expected6,
	nts::Tristate expected7,
	nts::Tristate expected8,
	nts::Tristate expected9,
	nts::Tristate expected10,
	nts::Tristate expected11,
	nts::Tristate expected12,
	nts::Tristate expected13,
	nts::Tristate expected14,
	nts::Tristate expected15,
	nts::Tristate expected16
)
{
	static unsigned int assertNumber = 1;
	component.setLink(2, i0, 1);
	component.setLink(3, i1, 1);
	component.setLink(21, i2, 1);
	component.setLink(22, i3, 1);

	component.setLink(23, inhibit, 1);


	cr_assert_eq(component.compute(11), expected1, "Assert%i: expected %i\n", assertNumber, expected1);
	assertNumber++;
	cr_assert_eq(component.compute(9), expected2, "Assert%i: expected %i\n", assertNumber, expected2);
	assertNumber++;
	cr_assert_eq(component.compute(10), expected3, "Assert%i: expected %i\n", assertNumber, expected3);
	assertNumber++;
	cr_assert_eq(component.compute(8), expected4, "Assert%i: expected %i\n", assertNumber, expected4);
	assertNumber++;
	cr_assert_eq(component.compute(7), expected5, "Assert%i: expected %i\n", assertNumber, expected5);
	assertNumber++;
	cr_assert_eq(component.compute(6), expected6, "Assert%i: expected %i\n", assertNumber, expected6);
	assertNumber++;
	cr_assert_eq(component.compute(5), expected7, "Assert%i: expected %i\n", assertNumber, expected7);
	assertNumber++;
	cr_assert_eq(component.compute(4), expected8, "Assert%i: expected %i\n", assertNumber, expected8);
	assertNumber++;
	cr_assert_eq(component.compute(18), expected9, "Assert%i: expected %i\n", assertNumber, expected9);
	assertNumber++;
	cr_assert_eq(component.compute(17), expected10, "Assert%i: expected %i\n", assertNumber, expected10);
	assertNumber++;
	cr_assert_eq(component.compute(20), expected11, "Assert%i: expected %i\n", assertNumber, expected11);
	assertNumber++;
	cr_assert_eq(component.compute(19), expected12, "Assert%i: expected %i\n", assertNumber, expected12);
	assertNumber++;
	cr_assert_eq(component.compute(14), expected13, "Assert%i: expected %i\n", assertNumber, expected13);
	assertNumber++;
	cr_assert_eq(component.compute(13), expected14, "Assert%i: expected %i\n", assertNumber, expected14);
	assertNumber++;
	cr_assert_eq(component.compute(16), expected15, "Assert%i: expected %i\n", assertNumber, expected15);
	assertNumber++;
	cr_assert_eq(component.compute(15), expected16, "Assert%i: expected %i\n", assertNumber, expected16);
	assertNumber++;
}

Test(CD4514BC, TruthTable, .init = cr_redirect_stdout)
{
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;
	nts::CD4514BC component;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	testComponent(component,
		iFalse, iFalse, iFalse, iFalse,
		iFalse,
		nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iTrue, iFalse, iFalse, iFalse,
		iFalse,
		nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iTrue, iFalse, iFalse,
		iFalse,
		nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iTrue, iTrue, iFalse, iFalse,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iFalse, iFalse, iTrue, iFalse,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iTrue, iFalse, iTrue, iFalse,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iFalse, iTrue, iTrue, iFalse,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iTrue, iTrue, iTrue, iFalse,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iFalse, iFalse, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iTrue, iFalse, iFalse, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iFalse, iTrue, iFalse, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iTrue, iTrue, iFalse, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	testComponent(component,
		iFalse, iFalse, iTrue, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iTrue, iFalse, iTrue, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iTrue, iTrue, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE);
	testComponent(component,
		iTrue, iTrue, iTrue, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE);

	// Undefined False
	testComponent(component,
		iUndefined, iFalse, iFalse, iFalse,
		iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iUndefined, iFalse, iFalse,
		iFalse,
		nts::UNDEFINED, nts::FALSE, nts::UNDEFINED, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iFalse, iUndefined, iFalse,
		iFalse,
		nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iFalse, iFalse, iUndefined,
		iFalse,
		nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iUndefined, iUndefined, iFalse, iFalse,
		iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iUndefined, iUndefined, iFalse,
		iFalse,
		nts::UNDEFINED, nts::FALSE, nts::UNDEFINED, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::UNDEFINED, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iFalse, iUndefined, iUndefined,
		iFalse,
		nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iUndefined, iFalse, iFalse, iUndefined,
		iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iUndefined, iFalse, iUndefined, iFalse,
		iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iUndefined, iFalse, iUndefined,
		iFalse,
		nts::UNDEFINED, nts::FALSE, nts::UNDEFINED, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::UNDEFINED, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iUndefined, iUndefined, iUndefined, iFalse,
		iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testComponent(component,
		iFalse, iUndefined, iUndefined, iUndefined,
		iFalse,
		nts::UNDEFINED, nts::FALSE, nts::UNDEFINED, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::UNDEFINED, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::UNDEFINED, nts::FALSE,
		nts::UNDEFINED, nts::FALSE, nts::UNDEFINED, nts::FALSE);
	testComponent(component,
		iUndefined, iFalse, iUndefined, iUndefined,
		iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE);
	testComponent(component,
		iUndefined, iUndefined, iFalse, iUndefined,
		iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);

	// Undefined True
	testComponent(component,
		iUndefined, iTrue, iTrue, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	testComponent(component,
		iTrue, iUndefined, iTrue, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED);
	testComponent(component,
		iTrue, iTrue, iUndefined, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED);
	testComponent(component,
		iTrue, iTrue, iTrue, iUndefined,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED);
	testComponent(component,
		iUndefined, iUndefined, iTrue, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	testComponent(component,
		iTrue, iUndefined, iUndefined, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED);
	testComponent(component,
		iTrue, iTrue, iUndefined, iUndefined,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED);
	testComponent(component,
		iUndefined, iTrue, iTrue, iUndefined,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	testComponent(component,
		iUndefined, iTrue, iUndefined, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	testComponent(component,
		iTrue, iUndefined, iTrue, iUndefined,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED);
	testComponent(component,
		iUndefined, iUndefined, iUndefined, iTrue,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	testComponent(component,
		iTrue, iUndefined, iUndefined, iUndefined,
		iFalse,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED);
	testComponent(component,
		iUndefined, iTrue, iUndefined, iUndefined,
		iFalse,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	testComponent(component,
		iUndefined, iUndefined, iTrue, iUndefined,
		iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);

	// Full Undefined

	testComponent(component,
		iUndefined, iUndefined, iUndefined, iUndefined,
		iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);

	// Inhibit pin
	testComponent(component,
		iFalse, iFalse, iFalse, iFalse,
		iUndefined,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	testComponent(component,
		iFalse, iFalse, iFalse, iFalse,
		iTrue,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
}