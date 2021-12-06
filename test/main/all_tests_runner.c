/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_tests_runner.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 21:49:59 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/30 21:53:15 by hyilmaz       ########   odam.nl         */
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