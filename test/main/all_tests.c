/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_tests.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:08:17 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/27 21:45:06 by hyilmaz       ########   odam.nl         */
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
	RUN_TEST_CASE(TestReturnAtoiWithIntOverflowCheck, NULL_PTR);
}

int	main(int argc, const char *argv[])
{
	return (UnityMain(argc, argv, run_all_tests));
}