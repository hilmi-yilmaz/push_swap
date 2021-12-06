/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_tests_runner.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 21:49:59 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/06 17:55:36 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unity_fixture.h>

TEST_GROUP_RUNNER(TestReturnAtoiWithIntOverflowCheck)
{
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, BasicIntegersUnsigned);
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, BasicIntegersSigned);
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, BasicIntegersSignedWithSpaces);
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, BasicIntegersSignedWithMisplacedSpaces);
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, BasicIntegersWithCharacters);
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, IntMaxandMin);
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, OutOfIntegerBounds);
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, OutOfLongBounds);
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, LotsOfZeros);
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, NULL_PTR);
}

TEST_GROUP_RUNNER(TestInputValidation)
{
	RUN_TEST_CASE(TestInputValidation, Duplicates);
	RUN_TEST_CASE(TestInputValidation, WrongCharacters);
	RUN_TEST_CASE(TestInputValidation, OutOfIntegerBounds);
	RUN_TEST_CASE(TestInputValidation, OneOrMoreInputsAreEmpty);
}

TEST_GROUP_RUNNER(TestSortingAlgorithms)
{
	RUN_TEST_CASE(TestSortingAlgorithms, BubbleSort);
}

TEST_GROUP_RUNNER(InitStacks)
{
	RUN_TEST_CASE(InitStacks, IndexArray);
	RUN_TEST_CASE(InitStacks, InitStackCompleteModuleCheck);
}

TEST_GROUP_RUNNER(TestOperations)
{
	RUN_TEST_CASE(TestOperations, TestRotateStack);
	RUN_TEST_CASE(TestOperations, TestPushToOtherStack);
	RUN_TEST_CASE(TestOperations, TestSwap);
	RUN_TEST_CASE(TestOperations, TestRotateAndPush);
	RUN_TEST_CASE(TestOperations, TestReverseRotate);
}

TEST_GROUP_RUNNER(TestRadixsort)
{
	RUN_TEST_CASE(TestRadixsort, RadixSort);
}

TEST_GROUP_RUNNER(TestThreeAndFiveLengthArrays)
{
	RUN_TEST_CASE(TestThreeAndFiveLengthArrays, ThreeLength);
}