/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_tests.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:08:17 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/27 16:23:00 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"

static void	run_all_tests(void)
{
	RUN_TEST_CASE(TestAtoiWithIntOverflowCheck, BasicIntegersUnsigned);
	RUN_TEST_CASE(TestAtoiWithIntOverflowCheck, BasicIntegersSigned);
	RUN_TEST_CASE(TestAtoiWithIntOverflowCheck, BasicIntegersSignedWithSpaces);
	RUN_TEST_CASE(TestAtoiWithIntOverflowCheck, BasicIntegersSignedWithMisplacedSpaces);
	RUN_TEST_CASE(TestAtoiWithIntOverflowCheck, IntMaxandMin);
	RUN_TEST_CASE(TestAtoiWithIntOverflowCheck, NULL_PTR);
}

int	main(int argc, const char *argv[])
{
	return (UnityMain(argc, argv, run_all_tests));
}