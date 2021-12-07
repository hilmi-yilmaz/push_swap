/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_init_stacks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 15:03:19 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 18:09:25 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Unity headers */
#include "unity_fixture.h"

/* System headers */
#include <stdarg.h>
#include <string.h>

/* Source files to test */
#include "../src/init_stacks.h"

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

static t_stack	*create_stack(int num_elements, ...)
{
	int		i;
	t_stack	*a;
	va_list	args;

	i = 0;
	a = calloc(1, sizeof(*a));
	a->num_elements = num_elements;
	a->stack = calloc(num_elements, sizeof(*a));
	va_start(args, num_elements);
	while (i < num_elements)
	{
		a->stack[i] = va_arg(args, int);
		i++;
	}
	return (a);
}

static void	free_stack(t_stack *a)
{
	free(a->stack);
	free(a);
}

TEST_GROUP(InitStacks);

TEST_SETUP(InitStacks)
{
}

TEST_TEAR_DOWN(InitStacks)
{
}

TEST(InitStacks, IndexArray)
{
	t_stack	*a;
	t_stack *idx;
	int		*sorted_array;
	int		len;
	
	len = 5;
	a = create_stack(len, 5, 4, 3, 2, 1);
	sorted_array = copy_array(a->stack, a->num_elements);
	bubble_sort(sorted_array, a->num_elements);
	idx = create_idx_stack(a);
	arange_a_stack_from_idx(a, idx, sorted_array);
	int	expected_a[] = {4, 3, 2, 1, 0};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_a, a->stack, len, "Input is \"5 4 3 2 1\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input len is 5");
	free_stack(a);
	free(sorted_array);

	len = 10;
	a = create_stack(len, 5, 4, 3, 2, 1, 6, 9, 8, 7, 10);
	sorted_array = copy_array(a->stack, a->num_elements);
	bubble_sort(sorted_array, a->num_elements);
	idx = create_idx_stack(a);
	arange_a_stack_from_idx(a, idx, sorted_array);
	int	expected_a1[] = {4, 3, 2, 1, 0, 5, 8, 7, 6, 9};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_a1, a->stack, len, "Input is \"5 4 3 2 1 6 9 8 7 10\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input len is 10");
	free_stack(a);
	free(sorted_array);

	len = 4;
	a = create_stack(len, 11, 10, 0, 8);
	sorted_array = copy_array(a->stack, a->num_elements);
	bubble_sort(sorted_array, a->num_elements);
	idx = create_idx_stack(a);
	arange_a_stack_from_idx(a, idx, sorted_array);
	int	expected_a2[] = {3, 2, 0, 1};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_a2, a->stack, len, "Input is \"11 10 0 8\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input len is 10");
	free_stack(a);
	free(sorted_array);
}

TEST(InitStacks, InitStackCompleteModuleCheck)
{	
	t_stack a;
	t_stack b;
	char	**argv;
	int		num_arguments;

	num_arguments = 4;
	argv = create_argv(num_arguments, "11", "10", "0", "8");
	int	expected_a[] = {3, 2, 0, 1};
	init_stacks(&a, &b, argv, num_arguments);
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_a, a.stack, num_arguments, "Input is \"11 10 0 8\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(num_arguments, a.num_elements, "Input len is 4");
	free(a.stack);
	free(b.stack);

	num_arguments = 6;
	argv = create_argv(num_arguments, "0", "-1", "-5", "10", "8", "-100");
	int	expected_a1[] = {3, 2, 1, 5, 4, 0};
	init_stacks(&a, &b, argv, num_arguments);
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_a1, a.stack, num_arguments, "Input is \"0 -1 -5 10 8 -100\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(num_arguments, a.num_elements, "Input len is 6");
	free(a.stack);
	free(b.stack);

	num_arguments = 12;
	argv = create_argv(num_arguments, "0", "-1", "-5", "10", "8", "-100", "-1000", "222", "12", "99", "-111", "-112");
	int	expected_a2[] = {6, 5, 4, 8, 7, 3, 0, 11, 9, 10, 2, 1};
	init_stacks(&a, &b, argv, num_arguments);
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_a2, a.stack, num_arguments, "Input is \"0 -1 -5 10 8 -100\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(num_arguments, a.num_elements, "Input len is 6");
	free(a.stack);
	free(b.stack);
}
