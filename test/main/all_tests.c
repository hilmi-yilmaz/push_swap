/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_tests.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:08:17 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 17:30:51 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"

static void	run_all_tests(void)
{
	RUN_TEST_GROUP(TestReturnAtoiWithIntOverflowCheck);
	RUN_TEST_GROUP(TestInputValidation);
	RUN_TEST_GROUP(TestSortingAlgorithms);
	RUN_TEST_GROUP(InitStacks);
	RUN_TEST_GROUP(TestOperations)
	RUN_TEST_GROUP(TestRadixsort);
	RUN_TEST_GROUP(TestThreeAndFiveLengthArrays);

}

int	main(int argc, const char *argv[])
{
	return (UnityMain(argc, argv, run_all_tests));
}