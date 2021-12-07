/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_sort_3_and_5.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 15:54:42 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 11:03:27 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Unity headers */
#include "unity_fixture.h"

/* System headers */
#include <stdarg.h>
#include <stdlib.h>

/* Source files to test */
#include "../src/sort_3_and_5.h"

static t_stack  *create_stack(int len_stack, int num_arguments, ...)
{
    int     i;
    t_stack *a;
    va_list args;

    i = 0;
    a = calloc(1, sizeof(*a));
    a->stack = calloc(len_stack, sizeof(*a->stack));
    va_start(args, num_arguments);
    while (i < num_arguments)
    {
        a->stack[i] = va_arg(args, int);
        i++;
    }
    a->num_elements = num_arguments;
    return (a);
}

TEST_GROUP(TestThreeAndFiveLengthArrays);

TEST_SETUP(TestThreeAndFiveLengthArrays)
{
}

TEST_TEAR_DOWN(TestThreeAndFiveLengthArrays)
{
}

TEST(TestThreeAndFiveLengthArrays, ThreeLength)
{
	t_stack *a;
	int		len;

	len = 3;
	a = create_stack(len, len, 1, 2, 4);
	sort_three(a);
	int	sorted_a[] = {1, 2, 4};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a, a->stack, len, "Input is \"1 2 4\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"1 2 4\"");
	free(a->stack);

	len = 3;
	a = create_stack(len, len, 1, 4, 2);
	sort_three(a);
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a, a->stack, len, "Input is \"1 4 2\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"1 4 2\"");
	free(a->stack);

	len = 3;
	a = create_stack(len, len, 2, 4, 1);
	sort_three(a);
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a, a->stack, len, "Input is \"2 4 1\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"2 4 1\"");
	free(a->stack);

	len = 3;
	a = create_stack(len, len, 2, 1, 4);
	sort_three(a);
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a, a->stack, len, "Input is \"2 1 4\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"2 1 4\"");
	free(a->stack);

	len = 3;
	a = create_stack(len, len, 4, 1, 2);
	sort_three(a);
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a, a->stack, len, "Input is \"4 1 2\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"4 1 2\"");
	free(a->stack);

	len = 3;
	a = create_stack(len, len, 4, 2, 1);
	sort_three(a);
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a, a->stack, len, "Input is \"4 2 1\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"4 2 1\"");
	free(a->stack);
}

TEST(TestThreeAndFiveLengthArrays, FiveLength)
{
	t_stack *a;
	t_stack	*b;
	int		len;

	len = 5;
	a = create_stack(len, len, 1, 2, 4, 0, 3);
	b = create_stack(len, 0);
	sort_five(a, b);
	int	sorted_a[] = {0, 1, 2, 3, 4};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a, a->stack, len, "Input is \"1 2 4 0 3\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"1 2 4 0 3\"");
	free(a->stack);
	free(b->stack);

	len = 5;
	a = create_stack(len, len, 4, 3, 2, 1, 0);
	b = create_stack(len, 0);
	sort_five(a, b);
	int	sorted_a_1[] = {0, 1, 2, 3, 4};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a_1, a->stack, len, "Input is \"4 3 2 1 0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"4 3 2 1 0\"");
	free(a->stack);
	free(b->stack);

	len = 5;
	a = create_stack(len, len, 3, 2, 4, 0, 1);
	b = create_stack(len, 0);
	sort_five(a, b);
	int	sorted_a_2[] = {0, 1, 2, 3, 4};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a_2, a->stack, len, "Input is \"3 2 4 0 1\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"3 2 4 0 1\"");
	free(a->stack);
	free(b->stack);
}
