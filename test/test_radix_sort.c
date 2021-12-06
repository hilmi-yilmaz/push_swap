/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_radix_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 12:22:11 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/06 15:40:40 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Unity headers */
#include "unity_fixture.h"

/* System headers */
#include <stdarg.h>
#include <stdlib.h>

/* Source files to test */
#include "../src/radix_sort.h"

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

TEST_GROUP(TestRadixsort);

TEST_SETUP(TestRadixsort)
{
}

TEST_TEAR_DOWN(TestRadixsort)
{
}

TEST(TestRadixsort, RadixSort)
{
	t_stack *a;
	t_stack *b;
	int		len;

	len = 2;
	a = create_stack(len, len, 2, 1);
	b = create_stack(len, 0);
	radix_sort(a, b);
	int	sorted_a[] = {1, 2};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a, a->stack, len, "Input is \"2 1\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"2 1\"");
	free(a->stack);
	free(b->stack);

	len = 3;
	a = create_stack(len, len, 4, 2, 1);
	b = create_stack(len, 0);
	radix_sort(a, b);
	int	sorted_a_1[] = {1, 2, 4};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a_1, a->stack, len, "Input is \"4 2 1\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"4 2 1\"");
	free(a->stack);
	free(b->stack);

	len = 5;
	a = create_stack(len, len, 10, 2, 7, 4, 0);
	b = create_stack(len, 0);
	radix_sort(a, b);
	int	sorted_a_2[] = {0, 2, 4, 7, 10};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a_2, a->stack, len, "Input is \"10 2 7 4 0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"10 2 7 4 0\"");
	free(a->stack);
	free(b->stack);

	len = 100;
	a = create_stack(len, len, 100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1);
	b = create_stack(len, 0);
	radix_sort(a, b);
	int	sorted_a_3[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_a_3, a->stack, len, "Input is \"10 2 7 4 0\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"10 2 7 4 0\"");
	free(a->stack);
	free(b->stack);
}