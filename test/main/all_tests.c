/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_tests.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:08:17 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/29 23:34:58 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"

static void	run_all_tests(void)
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

	RUN_TEST_CASE(TestInputValidation, Duplicates);
	RUN_TEST_CASE(TestInputValidation, WrongCharacters);
	RUN_TEST_CASE(TestInputValidation, OutOfIntegerBounds);
	RUN_TEST_CASE(TestInputValidation, OneOrMoreInputsAreEmpty);

	RUN_TEST_CASE(TestSortingAlgorithms, BubbleSort);

}

int	main(int argc, const char *argv[])
{
	return (UnityMain(argc, argv, run_all_tests));
}