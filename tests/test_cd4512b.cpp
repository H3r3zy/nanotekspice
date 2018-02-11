/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <CD4512B.hpp>
#include "Input.hpp"

static void testComponent(
	nts::IComponent &component,
	nts::Input &A,
	nts::Input &B,
	nts::Input &C,
	nts::Input &inhibit,
	nts::Input &enable,
	nts::Input &i0,
	nts::Input &i1,
	nts::Input &i2,
	nts::Input &i3,
	nts::Input &i4,
	nts::Input &i5,
	nts::Input &i6,
	nts::Input &i7,
	nts::Tristate expected1
)
{
	static unsigned int assertNumber = 1;
	component.setLink(1, i0, 1);
	component.setLink(2, i1, 1);
	component.setLink(3, i2, 1);
	component.setLink(4, i3, 1);
	component.setLink(5, i4, 1);
	component.setLink(6, i5, 1);
	component.setLink(7, i6, 1);
	component.setLink(9, i7, 1);

	component.setLink(11, A, 1);
	component.setLink(12, B, 1);
	component.setLink(13, C, 1);

	component.setLink(10, inhibit, 1);
	component.setLink(15, enable, 1);


	cr_assert_eq(component.compute(14), expected1, "Assert%i: expected %s\n", assertNumber, expected1);
	assertNumber++;
}

Test(CD4512B, TruthTable, .init = cr_redirect_stdout)
{
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;
	nts::CD4512B component;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);
	static int i = 1;

	testComponent(component, iFalse, iFalse, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);
	// 1

	testComponent(component, iTrue, iFalse, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);
	// 2

	testComponent(component, iFalse, iTrue, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);

	// 3
	testComponent(component, iTrue, iTrue, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);

	// 4
	testComponent(component, iFalse, iFalse, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);

	// 5
	testComponent(component, iTrue, iFalse, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);

	// 6
	testComponent(component, iFalse, iTrue, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);

	// 7
	testComponent(component, iTrue, iTrue, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);
	// 8


	testComponent(component, iFalse, iFalse, iFalse,
		iFalse, iFalse,
		iTrue, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::TRUE);
	// 9

	testComponent(component, iTrue, iFalse, iFalse,
		iFalse, iFalse,
		iFalse, iTrue, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::TRUE);

	// 10
	testComponent(component, iFalse, iTrue, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iTrue, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::TRUE);

	// 11
	testComponent(component, iTrue, iTrue, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iTrue, iFalse, iFalse, iFalse, iFalse,
		nts::TRUE);

	// 12
	testComponent(component, iFalse, iFalse, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iTrue, iFalse, iFalse, iFalse,
		nts::TRUE);

	// 13
	testComponent(component, iTrue, iFalse, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iTrue, iFalse, iFalse,
		nts::TRUE);

	// 14
	testComponent(component, iFalse, iTrue, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iTrue, iFalse,
		nts::TRUE);

	// 15
	testComponent(component, iTrue, iTrue, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iTrue,
		nts::TRUE);
	// 16


	testComponent(component, iFalse, iFalse, iFalse,
		iFalse, iFalse,
		iFalse, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue,
		nts::FALSE);

	// 17
	testComponent(component, iTrue, iFalse, iFalse,
		iFalse, iFalse,
		iTrue, iFalse, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue,
		nts::FALSE);

	// 18
	testComponent(component, iFalse, iTrue, iFalse,
		iFalse, iFalse,
		iTrue, iTrue, iFalse, iTrue, iTrue, iTrue, iTrue, iTrue,
		nts::FALSE);

	// 19
	testComponent(component, iTrue, iTrue, iFalse,
		iFalse, iFalse,
		iTrue, iTrue, iTrue, iFalse, iTrue, iTrue, iTrue, iTrue,
		nts::FALSE);

	// 20
	testComponent(component, iFalse, iFalse, iTrue,
		iFalse, iFalse,
		iTrue, iTrue, iTrue, iTrue, iFalse, iTrue, iTrue, iTrue,
		nts::FALSE);

	// 21
	testComponent(component, iTrue, iFalse, iTrue,
		iFalse, iFalse,
		iTrue, iTrue, iTrue, iTrue, iTrue, iFalse, iTrue, iTrue,
		nts::FALSE);

	// 22
	testComponent(component, iFalse, iTrue, iTrue,
		iFalse, iFalse,
		iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iFalse, iTrue,
		nts::FALSE);

	// 23
	testComponent(component, iTrue, iTrue, iTrue,
		iFalse, iFalse,
		iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iFalse,
		nts::FALSE);


	// 24
	testComponent(component, iFalse, iFalse, iFalse,
		iFalse, iFalse,
		iUndefined, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED);

	// 25
	testComponent(component, iTrue, iFalse, iFalse,
		iFalse, iFalse,
		iFalse, iUndefined, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED);

	// 26
	testComponent(component, iFalse, iTrue, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iUndefined, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED);

	// 27
	testComponent(component, iTrue, iTrue, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iUndefined, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED);

	// 28
	testComponent(component, iFalse, iFalse, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iUndefined, iFalse, iFalse, iFalse,
		nts::UNDEFINED);

	// 29
	testComponent(component, iTrue, iFalse, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iUndefined, iFalse, iFalse,
		nts::UNDEFINED);

	// 30
	testComponent(component, iFalse, iTrue, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iUndefined, iFalse,
		nts::UNDEFINED);

	// 31
	testComponent(component, iTrue, iTrue, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iUndefined,
		nts::UNDEFINED);


	// 32
	testComponent(component, iUndefined, iFalse, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED);

	// 33
	testComponent(component, iTrue, iUndefined, iFalse,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED);

	// 34
	testComponent(component, iFalse, iTrue, iUndefined,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED);

	// 35
	testComponent(component, iTrue, iTrue, iFalse,
		iFalse, iFalse,
		iUndefined, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);

	// 36
	testComponent(component, iFalse, iFalse, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iUndefined, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);

	// 37
	testComponent(component, iTrue, iFalse, iTrue,
		iFalse, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iUndefined, iFalse, iFalse,
		nts::UNDEFINED);

	// 38
	testComponent(component, iFalse, iTrue, iTrue,
		iFalse, iUndefined,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED);

	// 39
	testComponent(component, iTrue, iTrue, iTrue,
		iUndefined, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED);
	// 40


	// Options

	testComponent(component, iFalse, iFalse, iFalse,
		iTrue, iFalse,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE);

	// 41
	testComponent(component, iFalse, iFalse, iFalse,
		iTrue, iFalse,
		iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue,
		nts::FALSE);

	// 42
	testComponent(component, iTrue, iTrue, iTrue,
		iTrue, iFalse,
		iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue,
		nts::FALSE);

	// 43
	testComponent(component, iFalse, iFalse, iFalse,
		iFalse, iTrue,
		iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::TRUE);
	// 44
}