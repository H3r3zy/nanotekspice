/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "RSNorLatchComponent.hpp"
#include "Input.hpp"

nts::RSNorLatchComponent component;

void testRSNorLatchComponent(nts::Input &set,
	nts::Input &reset,
	nts::Tristate expected1,
	nts::Tristate expected2
)
{
	static int assertNumber = 1;
	component.setLink(1, set, 1);
	component.setLink(2, reset, 1);

	cr_assert_eq(component.compute(3), expected1, "Assert%i: expected %i", assertNumber, expected1);
	assertNumber++;
	cr_assert_eq(component.compute(4), expected2, "Assert%i: expected %i", assertNumber, expected2);
	assertNumber++;
}

Test(RSNorLatchComponent, TruthTable, .init = cr_redirect_stdout)
{
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	testRSNorLatchComponent(iFalse, iFalse, nts::UNDEFINED, nts::UNDEFINED);
	testRSNorLatchComponent(iFalse, iTrue, nts::FALSE, nts::TRUE);
	testRSNorLatchComponent(iTrue, iFalse, nts::TRUE, nts::FALSE);
	testRSNorLatchComponent(iFalse, iFalse, nts::TRUE, nts::FALSE);
	testRSNorLatchComponent(iTrue, iTrue, nts::UNDEFINED, nts::UNDEFINED);
	testRSNorLatchComponent(iUndefined, iFalse, nts::UNDEFINED, nts::UNDEFINED);
	testRSNorLatchComponent(iFalse, iUndefined, nts::UNDEFINED, nts::UNDEFINED);
	testRSNorLatchComponent(iTrue, iUndefined, nts::UNDEFINED, nts::UNDEFINED);
	testRSNorLatchComponent(iUndefined, iTrue, nts::UNDEFINED, nts::UNDEFINED);
	testRSNorLatchComponent(iUndefined, iUndefined, nts::UNDEFINED, nts::UNDEFINED);
}

Test(RSNorLatchComponent, dump, .init = cr_redirect_stdout)
{
component.dump();

cr_assert_stdout_eq_str("RSNorLatch Component\n", "Dump error");
}

Test(RSNorLatchComponent, copy, .init = cr_redirect_stdout)
{
auto c1 = new nts::RSNorLatchComponent();
auto c2 = c1->copy();

cr_assert_neq(c1, c2);

delete c1;
delete c2;
}

Test(RSNorLatchComponent, equalConstructor, .init = cr_redirect_stdout)
{
nts::RSNorLatchComponent c1;
nts::RSNorLatchComponent c2;
c2 = c1;
cr_assert_neq(&c1, &c2);
}