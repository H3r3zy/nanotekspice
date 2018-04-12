/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <FullAdderComponent.hpp>
#include <CD4008BMS.hpp>
#include "NandGate.hpp"
#include "Input.hpp"

nts::CD4008BMS cd4008bms;

void testCD4008BMS(nts::Input &i1,
	nts::Input &i2,
	nts::Input &i3,
	nts::Input &i4,
	nts::Input &i5,
	nts::Input &i6,
	nts::Input &i7,
	nts::Input &i8,
	nts::Input &cin,
	nts::Tristate expected1,
	nts::Tristate expected2,
	nts::Tristate expected3,
	nts::Tristate expected4,
	nts::Tristate expected5
)
{
	static int assertNumber = 1;
	cd4008bms.setLink(7, i1, 1);
	cd4008bms.setLink(6, i2, 1);
	cd4008bms.setLink(5, i3, 1);
	cd4008bms.setLink(4, i4, 1);
	cd4008bms.setLink(3, i5, 1);
	cd4008bms.setLink(2, i6, 1);
	cd4008bms.setLink(1, i7, 1);
	cd4008bms.setLink(15, i8, 1);
	cd4008bms.setLink(9, cin, 1);

	cr_assert_eq(cd4008bms.compute(10), expected1, "Assert%i: Expected %i", assertNumber, expected1);
	assertNumber++;
	cr_assert_eq(cd4008bms.compute(11), expected2, "Assert%i: Expected %i", assertNumber, expected2);
	assertNumber++;
	cr_assert_eq(cd4008bms.compute(12), expected3, "Assert%i: Expected %i", assertNumber, expected3);
	assertNumber++;
	cr_assert_eq(cd4008bms.compute(13), expected4, "Assert%i: Expected %i", assertNumber, expected4);
	assertNumber++;
	cr_assert_eq(cd4008bms.compute(14), expected5, "Assert%i: Expected %i", assertNumber, expected5);
	assertNumber++;
}

Test(CD4008BMS, TruthTable, .init = cr_redirect_stdout)
{
	nts::Input iTrue;
	nts::Input iFalse;
	nts::Input iUndefined;

	iTrue.setValue(nts::TRUE);
	iFalse.setValue(nts::FALSE);

	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	// 00000 : 5
	testCD4008BMS(iTrue, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	// 00001 : 10
	testCD4008BMS(iTrue, iTrue, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE);
	// 00010 : 15
	testCD4008BMS(iTrue, iTrue, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iTrue,
		nts::TRUE, nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE);
	// 00011 : 20
	testCD4008BMS(iFalse, iFalse, iTrue, iTrue, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE);
	// 00100 : 25
	testCD4008BMS(iTrue, iFalse, iTrue, iTrue, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE);
	// 00101 : 30
	testCD4008BMS(iTrue, iTrue, iTrue, iTrue, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE, nts::FALSE);
	// 00110 : 35
	testCD4008BMS(iTrue, iTrue, iTrue, iTrue, iFalse, iFalse, iFalse, iFalse, iTrue,
		nts::TRUE, nts::TRUE, nts::TRUE, nts::FALSE, nts::FALSE);
	// 00111 : 40
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iTrue, iFalse, iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE);
	// 01000 : 45
	testCD4008BMS(iTrue, iFalse, iFalse, iFalse, iFalse, iFalse, iTrue, iFalse, iFalse,
		nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE);
	// 01001 : 50
	testCD4008BMS(iTrue, iTrue, iFalse, iFalse, iFalse, iFalse, iTrue, iFalse, iFalse,
		nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE);
	// 01010 : 55
	testCD4008BMS(iTrue, iTrue, iFalse, iFalse, iFalse, iFalse, iTrue, iFalse, iTrue,
		nts::TRUE, nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE);
	// 01011 : 60
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iTrue, iFalse, iTrue, iFalse, iFalse,
		nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE);
	// 01100 : 65
	testCD4008BMS(iTrue, iFalse, iFalse, iFalse, iTrue, iFalse, iTrue, iFalse, iFalse,
		nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE);
	// 01101 : 70
	testCD4008BMS(iFalse, iFalse, iTrue, iFalse, iTrue, iFalse, iTrue, iFalse, iFalse,
		nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE, nts::FALSE);
	// 01110 : 75
	testCD4008BMS(iTrue, iFalse, iTrue, iFalse, iTrue, iFalse, iTrue, iFalse, iFalse,
		nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE, nts::FALSE);
	// 01111 : 80
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iTrue, iTrue, iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE);
	// 10000 : 85
	testCD4008BMS(iTrue, iFalse, iFalse, iFalse, iFalse, iFalse, iTrue, iTrue, iFalse,
		nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE);
	// 10001 : 90
	testCD4008BMS(iFalse, iFalse, iTrue, iFalse, iFalse, iFalse, iTrue, iTrue, iFalse,
		nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE);
	// 10010 : 95
	testCD4008BMS(iTrue, iFalse, iTrue, iFalse, iFalse, iFalse, iTrue, iTrue, iFalse,
		nts::TRUE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE);
	// 10011 : 100
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iTrue, iFalse, iTrue, iTrue, iFalse,
		nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE);
	// 10100 : 105
	testCD4008BMS(iTrue, iFalse, iFalse, iFalse, iTrue, iFalse, iTrue, iTrue, iFalse,
		nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE);
	// 10101 : 110
	testCD4008BMS(iFalse, iFalse, iTrue, iFalse, iTrue, iFalse, iTrue, iTrue, iFalse,
		nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE, nts::TRUE);
	// 10110 : 115
	testCD4008BMS(iTrue, iFalse, iTrue, iFalse, iTrue, iFalse, iTrue, iTrue, iFalse,
		nts::TRUE, nts::TRUE, nts::TRUE, nts::FALSE, nts::TRUE);
	// 10111 : 120
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iTrue, iTrue, iTrue, iTrue, iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE);
	// 11000 : 125
	testCD4008BMS(iTrue, iFalse, iFalse, iFalse, iTrue, iTrue, iTrue, iTrue, iFalse,
		nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE);
	// 11001 : 130
	testCD4008BMS(iFalse, iFalse, iTrue, iFalse, iTrue, iTrue, iTrue, iTrue, iFalse,
		nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE);
	// 11010 : 135
	testCD4008BMS(iTrue, iFalse, iTrue, iFalse, iTrue, iTrue, iTrue, iTrue, iFalse,
		nts::TRUE, nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE);
	// 11011 : 140
	testCD4008BMS(iFalse, iFalse, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iFalse,
		nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE);
	// 11100 : 145
	testCD4008BMS(iTrue, iFalse, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iFalse,
		nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE);
	// 11101 : 150
	testCD4008BMS(iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iFalse,
		nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);
	// 11110 : 155
	testCD4008BMS(iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue,
		nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);
	// 11111 : 160
	testCD4008BMS(iUndefined, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	// 0000? : 165
	testCD4008BMS(iFalse, iFalse, iUndefined, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE);
	// 000?0 : 170
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iUndefined, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::FALSE, nts::FALSE);
	// 00?00 : 175
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iUndefined, iFalse, iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::FALSE);
	// 0?000 : 180
	testCD4008BMS(iUndefined, iFalse, iUndefined, iFalse, iFalse, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE, nts::FALSE);
	// 000?? : 185
	testCD4008BMS(iFalse, iFalse, iUndefined, iFalse, iUndefined, iFalse, iFalse, iFalse, iFalse,
		nts::FALSE, nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE);
	// 00??0 : 190
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iUndefined, iFalse, iUndefined, iFalse, iFalse,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED, nts::FALSE);
	// 0??00 : 195
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iFalse, iFalse, iUndefined, iUndefined, iFalse,
		nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	// ??000 : 200
	testCD4008BMS(iUndefined, iFalse, iUndefined, iFalse, iUndefined, iFalse, iFalse, iFalse, iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE);
	// 00??? : 205
	testCD4008BMS(iFalse, iFalse, iUndefined, iFalse, iUndefined, iFalse, iUndefined, iFalse, iFalse,
		nts::FALSE, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::FALSE);
	// 0???0 : 210
	testCD4008BMS(iFalse, iFalse, iFalse, iFalse, iUndefined, iFalse, iUndefined, iUndefined, iFalse,
		nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	// ???00 : 215
	testCD4008BMS(iUndefined, iFalse, iUndefined, iFalse, iUndefined, iFalse, iUndefined, iFalse, iFalse,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::FALSE);
	// 0???? : 220
	testCD4008BMS(iFalse, iFalse, iUndefined, iFalse, iUndefined, iFalse, iUndefined, iUndefined, iFalse,
		nts::FALSE, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	// ????0 : 225
	testCD4008BMS(iUndefined, iUndefined, iUndefined, iUndefined, iUndefined, iUndefined, iUndefined, iUndefined, iUndefined,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	// 1111? : 230
	testCD4008BMS(iTrue, iTrue, iUndefined, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue,
		nts::TRUE, nts::UNDEFINED, nts::TRUE, nts::TRUE, nts::TRUE);
	// 111?1 : 235
	testCD4008BMS(iTrue, iTrue, iTrue, iTrue, iUndefined, iTrue, iTrue, iTrue, iTrue,
		nts::TRUE, nts::TRUE, nts::UNDEFINED, nts::TRUE, nts::TRUE);
	// 11?11 : 240
	testCD4008BMS(iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iUndefined, iTrue, iTrue,
		nts::TRUE, nts::TRUE, nts::TRUE, nts::UNDEFINED, nts::TRUE);
	// 1?111 : 245
	testCD4008BMS(iUndefined, iTrue, iUndefined, iTrue, iTrue, iTrue, iTrue, iTrue, iTrue,
		nts::UNDEFINED, nts::UNDEFINED, nts::TRUE, nts::TRUE, nts::TRUE);
	// 111?? : 250
	testCD4008BMS(iTrue, iTrue, iUndefined, iTrue, iUndefined, iTrue, iTrue, iTrue, iTrue,
		nts::TRUE, nts::UNDEFINED, nts::UNDEFINED, nts::TRUE, nts::TRUE);
	// 11??1 : 255
	testCD4008BMS(iTrue, iTrue, iTrue, iTrue, iUndefined, iTrue, iUndefined, iTrue, iTrue,
		nts::TRUE, nts::TRUE, nts::UNDEFINED, nts::UNDEFINED, nts::TRUE);
	// 1??11 : 260
	testCD4008BMS(iTrue, iTrue, iTrue, iTrue, iTrue, iTrue, iUndefined, iUndefined, iTrue,
		nts::TRUE, nts::TRUE, nts::TRUE, nts::UNDEFINED, nts::UNDEFINED);
	// ??111 : 265
	testCD4008BMS(iUndefined, iTrue, iUndefined, iTrue, iUndefined, iTrue, iTrue, iTrue, iTrue,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::TRUE, nts::TRUE);
	// 11??? : 270
	testCD4008BMS(iTrue, iTrue, iUndefined, iTrue, iUndefined, iTrue, iUndefined, iTrue, iTrue,
		nts::TRUE, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::TRUE);
	// 1???1 : 275
	testCD4008BMS(iTrue, iTrue, iTrue, iTrue, iUndefined, iTrue, iUndefined, iUndefined, iTrue,
		nts::TRUE, nts::TRUE, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	// ???11 : 280
	testCD4008BMS(iUndefined, iTrue, iUndefined, iTrue, iUndefined, iTrue, iUndefined, iTrue, iTrue,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::TRUE);
	// 1???? : 285
	testCD4008BMS(iTrue, iTrue, iUndefined, iTrue, iUndefined, iTrue, iUndefined, iUndefined, iTrue,
		nts::TRUE, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	// 1???? : 290
	testCD4008BMS(iUndefined, iUndefined, iUndefined, iTrue, iUndefined, iTrue, iTrue, iTrue, iUndefined,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::TRUE);
	// ????1 : 295
	testCD4008BMS(iUndefined, iUndefined, iUndefined, iUndefined, iUndefined, iUndefined, iUndefined, iUndefined, iUndefined,
		nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	// ????? : 300
}


Test(CD4008BMS, dump, .init = cr_redirect_stdout)
{
nts::CD4008BMS gate;
gate.dump();

cr_assert_stdout_eq_str("CD4008BMS Chipset\n", "Dump error");
}

Test(CD4008BMS, copy, .init = cr_redirect_stdout)
{
auto c1 = new nts::CD4008BMS();
auto c2 = c1->copy();

cr_assert_neq(c1, c2);

delete c1;
delete c2;
}

Test(CD4008BMS, equalConstructor, .init = cr_redirect_stdout)
{
nts::CD4008BMS c1;
nts::CD4008BMS c2;
c2 = c1;
cr_assert_neq(&c1, &c2);
}