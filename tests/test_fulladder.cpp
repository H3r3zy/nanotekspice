/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <FullAdderComponent.hpp>
#include "NandGate.hpp"
#include "Input.hpp"

nts::FullAdderComponent adder;

const char *takeTristateString(nts::Tristate t)
{
	if (t == nts::FALSE)
		return "False";
	else if (t == nts::TRUE)
		return "True";
	return "Undefined";
}

void testFullAdder(nts::Input &i1, nts::Input &i2, nts::Input &i3, nts::Tristate expected1, nts::Tristate expected2)
{
	static int assertNumber = 1;
	adder.setLink(1, i1, 1);
	adder.setLink(2, i2, 1);
	adder.setLink(3, i3, 1);
	const char *string = takeTristateString(expected1);

	cr_assert_eq(adder.compute(4), expected1, "Assert%i: expected %s\n", assertNumber, string);
	assertNumber++;
	string = takeTristateString(expected2);
	cr_assert_eq(adder.compute(5), expected2, "Assert%i: expected %s\n", assertNumber, string);
	assertNumber++;
}

Test(FullAdder, TruthTable, .init = cr_redirect_stdout)
{
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	testFullAdder(iFalse, iFalse, iFalse, nts::FALSE, nts::FALSE);
	testFullAdder(iFalse, iFalse, iTrue,  nts::FALSE, nts::TRUE);
	testFullAdder(iFalse, iTrue,  iFalse, nts::FALSE, nts::TRUE);
	testFullAdder(iTrue,  iFalse, iFalse, nts::FALSE, nts::TRUE);
	testFullAdder(iFalse, iTrue,  iTrue,  nts::TRUE,  nts::FALSE);
	testFullAdder(iTrue,  iTrue,  iFalse, nts::TRUE,  nts::FALSE);
	testFullAdder(iTrue,  iFalse, iTrue,  nts::TRUE,  nts::FALSE);
	testFullAdder(iTrue,  iTrue,  iTrue,  nts::TRUE,  nts::TRUE);

	testFullAdder(iUndefined, iFalse, iFalse, nts::FALSE, nts::UNDEFINED);
	testFullAdder(iFalse, iUndefined, iFalse, nts::FALSE, nts::UNDEFINED);
	testFullAdder(iFalse, iFalse, iUndefined, nts::FALSE, nts::UNDEFINED);

	testFullAdder(iUndefined, iTrue, iFalse, nts::UNDEFINED, nts::UNDEFINED);
	testFullAdder(iFalse, iUndefined, iTrue, nts::UNDEFINED, nts::UNDEFINED);
	testFullAdder(iTrue, iFalse, iUndefined, nts::UNDEFINED, nts::UNDEFINED);

	testFullAdder(iFalse, iTrue, iUndefined, nts::UNDEFINED, nts::UNDEFINED);
	testFullAdder(iUndefined, iFalse, iTrue, nts::UNDEFINED, nts::UNDEFINED);
	testFullAdder(iTrue, iUndefined, iFalse, nts::UNDEFINED, nts::UNDEFINED);

	testFullAdder(iTrue, iTrue, iUndefined, nts::TRUE, nts::UNDEFINED);
	testFullAdder(iTrue, iUndefined, iTrue, nts::TRUE, nts::UNDEFINED);
	testFullAdder(iUndefined, iTrue, iTrue, nts::TRUE, nts::UNDEFINED);

	testFullAdder(iFalse, iUndefined, iUndefined, nts::UNDEFINED, nts::UNDEFINED);
	testFullAdder(iUndefined, iUndefined, iFalse, nts::UNDEFINED, nts::UNDEFINED);
	testFullAdder(iUndefined, iFalse, iUndefined, nts::UNDEFINED, nts::UNDEFINED);

	testFullAdder(iTrue, iUndefined, iUndefined, nts::UNDEFINED, nts::UNDEFINED);
	testFullAdder(iUndefined, iUndefined, iTrue, nts::UNDEFINED, nts::UNDEFINED);
	testFullAdder(iUndefined, iTrue, iUndefined, nts::UNDEFINED, nts::UNDEFINED);

	testFullAdder(iUndefined, iUndefined, iUndefined, nts::UNDEFINED, nts::UNDEFINED);
}