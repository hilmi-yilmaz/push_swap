/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_validation.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:42:17 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/30 00:19:59 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "unity_memory.h"
#include "unity.h"

#include "../src/data.h"
#include "../src/input_validation.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static char	**argv = NULL;
static int	err;

static char	**create_argv(int amount_arguments, ...)
{
	int				i;
	char			**argv;
	char			*tmp;
	unsigned int	len;
	va_list			args;
	
	i = 0;
	argv = calloc(amount_arguments + 1, sizeof(*argv));
	va_start(args, amount_arguments);
	while (i < amount_arguments)
	{
		tmp = va_arg(args, char *);
		len = strlen(tmp);
		argv[i] = calloc(len + 1, sizeof(*argv[i]));
		memcpy(argv[i], tmp, len + 1);
		i++;
	}
	va_end(args);
	return (argv);
}

static void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

TEST_GROUP(TestInputValidation);


TEST_SETUP(TestInputValidation)
{
	err = 0;
}

TEST_TEAR_DOWN(TestInputValidation)
{
}

TEST(TestInputValidation, Duplicates)
{
	int	array[] = {1, 2, 2, 3, 4, 5, 6};
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_for_duplicates(array, 7), "Input is {1, 2, 2, 3, 4, 5, 6}");

	int	array1[] = {1, 2, 3, 4, 5, 6};
	TEST_ASSERT_EQUAL_INT_MESSAGE(SUCCES, check_for_duplicates(array1, 6), "Input is {1, 2, 3, 4, 5, 6}");

	int	array2[] = {};
	TEST_ASSERT_EQUAL_INT_MESSAGE(SUCCES, check_for_duplicates(array2, 0), "Input is {}");

	int	array3[] = {-10, -7, -7, -5, -4, -3, -1, 10};
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_for_duplicates(array3, 8), "Input is {-10, -7, -7, -5, -4, -3, -1, 10}");

	int	*array4 = NULL;
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_for_duplicates(array4, 0), "Input is NULL");
}

TEST(TestInputValidation, WrongCharacters)
{
	argv = create_argv(5, "1", "2", "3", "4", "5");
	TEST_ASSERT_EQUAL_INT_MESSAGE(SUCCES, check_for_wrong_characters(argv), "Input is \"1 2 3 4 5\"");
	free_argv(argv);

	argv = create_argv(6, "1", ".", "2", "3", "4", "5");
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_for_wrong_characters(argv), "Input is \"1 . 2 3 4 5\"");
	free_argv(argv);

	argv = create_argv(5, "1", "2p", "3", "4", "5");
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_for_wrong_characters(argv), "Input is \"1 2p 3 4 5\"");
	free_argv(argv);
}

TEST(TestInputValidation, OutOfIntegerBounds)
{
	argv = create_argv(5, "1111111111111111111111", "2", "3", "4", "5");
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_all_are_integers(argv), "Input is \"1111111111111111111111 2 3 4 5\"");
	free_argv(argv);

	argv = create_argv(5, "1", "2", "3", "4", "-5999999999999999999");
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_all_are_integers(argv), "Input is \"1 2 3 4 -5999999999999999999\"");
	free_argv(argv);

	argv = create_argv(5, "1", "2", "3", "2147483647", "2147483648");
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_all_are_integers(argv), "Input is \"1 2 3 2147483647 2147483648\"");
	free_argv(argv);

	argv = create_argv(5, "1", "2", "3", "2147483647", "-2147483648");
	TEST_ASSERT_EQUAL_INT_MESSAGE(SUCCES, check_all_are_integers(argv), "Input is \"1 2 3 2147483647 -2147483648\"");
	free_argv(argv);

	argv = create_argv(5, "1", "2", "3", "2147483649", "-2147483648");
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_all_are_integers(argv), "Input is \"1 2 3 2147483649 -2147483648\"");
	free_argv(argv);
}

TEST(TestInputValidation, OneOrMoreInputsAreEmpty)
{
	argv = create_argv(5, "1", "", "3", "4", "5");
	TEST_ASSERT_EQUAL_INT_MESSAGE(FAILURE, check_for_wrong_characters(argv), "Input is \"1 "" 3 4 5\"");
	free_argv(argv);
}