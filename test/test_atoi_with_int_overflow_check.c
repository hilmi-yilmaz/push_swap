/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_atoi_with_int_overflow_check.c                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:10:58 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/27 16:33:29 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "../src/atoi_with_int_overflow_check.h"

TEST_GROUP(TestAtoiWithIntOverflowCheck);

TEST_SETUP(TestAtoiWithIntOverflowCheck)
{
}

TEST_TEAR_DOWN(TestAtoiWithIntOverflowCheck)
{
}

TEST(TestAtoiWithIntOverflowCheck, BasicIntegersUnsigned)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("0"), "Input is \"0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("1467"), "Input is \"1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("1128569"), "Input is \"1128569\"");
}

TEST(TestAtoiWithIntOverflowCheck, BasicIntegersSigned)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("+0"), "Input is \"+0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("-0"), "Input is \"-0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("+1467"), "Input is \"+1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("-1467"), "Input is \"-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("+1128569"), "Input is \"+1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1128569, atoi_with_int_overflow_check("-1128569"), "Input is \"-1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1128569, atoi_with_int_overflow_check("---1128569"), "Input is \"---1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("--1128569"), "Input is \"--1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("+-1467"), "Input is \"+-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("-+-+-1467"), "Input is \"-+-+-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("-+-+1467"), "Input is \"-+-+1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("+++1467"), "Input is \"+++1467\"");
}

TEST(TestAtoiWithIntOverflowCheck, BasicIntegersSignedWithSpaces)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("   +0"), "Input is \"   +0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, atoi_with_int_overflow_check("   -0"), "Input is \"   -0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check(" +1467"), "Input is \" +1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("   -1467"), "Input is \"   -1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("   +1128569"), "Input is \"   +1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1128569, atoi_with_int_overflow_check("    -1128569"), "Input is \"    -1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1128569, atoi_with_int_overflow_check("    ---1128569"), "Input is \"    ---1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1128569, atoi_with_int_overflow_check("   --1128569"), "Input is \"   --1128569\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("  +-1467"), "Input is \"  +-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1467, atoi_with_int_overflow_check("   -+-+-1467"), "Input is \"   -+-+-1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("   -+-+1467"), "Input is \"   -+-+1467\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1467, atoi_with_int_overflow_check("    +++1467"), "Input is \"    +++1467\"");
}

TEST(TestAtoiWithIntOverflowCheck, BasicIntegersSignedWithMisplacedSpaces)
{
	TEST_IGNORE();
}

TEST(TestAtoiWithIntOverflowCheck, IntMaxandMin)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(2147483647, atoi_with_int_overflow_check("2147483647"), "Input is \"2147483647\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-2147483648, atoi_with_int_overflow_check("-2147483648"), "Input is \"-2147483648\"");
}

TEST(TestAtoiWithIntOverflowCheck, NULL_PTR)
{
	TEST_IGNORE();
}