/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_atoi_with_int_overflow_check.c                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:10:58 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/27 21:47:29 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "../src/atoi_with_int_overflow_check.h"

static int err;

TEST_GROUP(TestReturnAtoiWithIntOverflowCheck);

TEST_SETUP(TestReturnAtoiWithIntOverflowCheck)
{
}

TEST_TEAR_DOWN(TestReturnAtoiWithIntOverflowCheck)
{
}

TEST(TestReturnAtoiWithIntOverflowCheck, BasicIntegersUnsigned)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("0", &err), "Input is \"0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"0\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("1467", &err), "Input is \"1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("1128569", &err), "Input is \"1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"1128569\"");
}

TEST(TestReturnAtoiWithIntOverflowCheck, BasicIntegersSigned)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("+0", &err), "Input is \"+0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"+0\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("-0", &err), "Input is \"-0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"-0\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("+1467", &err), "Input is \"+1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"+1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("-1467", &err), "Input is \"-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"-1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("+1128569", &err), "Input is \"+1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"+1128569\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1128569, atoi_with_int_overflow_check("-1128569", &err), "Input is \"-1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"-1128569\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1128569, atoi_with_int_overflow_check("---1128569", &err), "Input is \"---1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"---1128569\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("--1128569", &err), "Input is \"--1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"--1128569\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("+-1467", &err), "Input is \"+-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"+-1467\"");
	
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("-+-+-1467", &err), "Input is \"-+-+-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"-+-+-1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("-+-+1467", &err), "Input is \"-+-+1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"-+-+1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("+++1467", &err), "Input is \"+++1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"+++1467\"");
}

TEST(TestReturnAtoiWithIntOverflowCheck, BasicIntegersSignedWithSpaces)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("   +0", &err), "Input is \"   +0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"   +0\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("   -0", &err), "Input is \"   -0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"   -0\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check(" +1467", &err), "Input is \" +1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \" +1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("   -1467", &err), "Input is \"   -1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"   -1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("   +1128569", &err), "Input is \"   +1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"   +1128569\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1128569, atoi_with_int_overflow_check("    -1128569", &err), "Input is \"    -1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"    -1128569\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1128569, atoi_with_int_overflow_check("    ---1128569", &err), "Input is \"    ---1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"    ---1128569\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("   --1128569", &err), "Input is \"   --1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"   --1128569\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("  +-1467", &err), "Input is \"  +-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"  +-1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("   -+-+-1467", &err), "Input is \"   -+-+-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"   -+-+-1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("   -+-+1467", &err), "Input is \"   -+-+1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"   -+-+1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("    +++1467", &err), "Input is \"    +++1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"    +++1467\"");
}

TEST(TestReturnAtoiWithIntOverflowCheck, BasicIntegersSignedWithMisplacedSpaces)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(14, atoi_with_int_overflow_check(" +14  67", &err), "Input is \" +14  67\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \" +14  67\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(-146, atoi_with_int_overflow_check("   -146   7", &err), "Input is \"   -146   7\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"   -146   7\"");
}

TEST(TestReturnAtoiWithIntOverflowCheck, BasicIntegersWithCharacters)
{
	atoi_with_int_overflow_check(" +a1467", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \" +a1467\"");

	atoi_with_int_overflow_check("   ;-1467", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"   ;-1467\"");

	atoi_with_int_overflow_check("a1467", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"a1467\"");

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, atoi_with_int_overflow_check("1a467", &err), "Input is \"1a467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"1a467\"");
}

TEST(TestReturnAtoiWithIntOverflowCheck, IntMaxandMin)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(2147483647, atoi_with_int_overflow_check("2147483647", &err), "Input is \"2147483647\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"2147483647\"");
	
	TEST_ASSERT_EQUAL_INT_MESSAGE(-2147483648, atoi_with_int_overflow_check("-2147483648", &err), "Input is \"-2147483648\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, err, "err: Input is \"-2147483648\"");
}

TEST(TestReturnAtoiWithIntOverflowCheck, OutOfIntegerBounds)
{
	atoi_with_int_overflow_check("2147483648", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"2147483648\"");

	atoi_with_int_overflow_check("-2147483649", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"-2147483649\"");

	atoi_with_int_overflow_check("214748364999", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"214748364999\"");

	atoi_with_int_overflow_check("-214748364999", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"-214748364999\"");
}

TEST(TestReturnAtoiWithIntOverflowCheck, OutOfLongBounds)
{
	atoi_with_int_overflow_check("214748364888888888888888888888888888888888888888", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"214748364888888888888888888888888888888888888888\"");

	atoi_with_int_overflow_check("-214748364888888888888888888888888888888888888888", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"-214748364888888888888888888888888888888888888888\"");

	atoi_with_int_overflow_check("214748364999999999999999999999999999999999999999999999999999999999", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"214748364999999999999999999999999999999999999999999999999999999999\"");

	atoi_with_int_overflow_check("-214748364999999999999999999999999999999999999999999999999999999999", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"-214748364999999999999999999999999999999999999999999999999999999999\"");

	atoi_with_int_overflow_check("214748364777777777777777777777777777777777777777777777777777777777777", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"214748364777777777777777777777777777777777777777777777777777777777777\"");

	atoi_with_int_overflow_check("-214748364777777777777777777777777777777777777777777777777777777777777", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"-214748364777777777777777777777777777777777777777777777777777777777777\"");

	atoi_with_int_overflow_check("9999999999999999999999999999999999999999999999999999999999999999999999999999", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"9999999999999999999999999999999999999999999999999999999999999999999999999999\"");

	atoi_with_int_overflow_check("-9999999999999999999999999999999999999999999999999999999999999999999999999999", &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "err: Input is \"-9999999999999999999999999999999999999999999999999999999999999999999999999999\"");
}

TEST(TestReturnAtoiWithIntOverflowCheck, NULL_PTR)
{
	atoi_with_int_overflow_check(NULL, &err);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, err, "Input is NULL");
}