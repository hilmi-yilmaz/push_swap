/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 10:34:50 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 11:21:41 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Unity headers */
#include "unity_fixture.h"

/* System headers */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* Source files to test */
#include "../src/operations.h"

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

TEST_GROUP(TestOperations);

TEST_SETUP(TestOperations)
{
}

TEST_TEAR_DOWN(TestOperations)
{
}

TEST(TestOperations, TestRotateStack)
{
    t_stack *a;
    int     len;

    len = 5;
    a = create_stack(len, len, 1, 2, 3, 4, 5);
    rotate(a);
    int expected[] = {2, 3, 4, 5, 1};
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected, a->stack, len, "Input is \"1 2 3 4 5\"");
    TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input len is 5");
    free(a->stack);

    len = 1;
    a = create_stack(len, len, 1);
    rotate(a);
    int expected1[] = {1};
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected1, a->stack, len, "Input is \"1\"");
    TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input len is 1");
    free(a->stack);

    len = 10;
    a = create_stack(len, len, 10, 8, 11, 99, 14, -1, 37, 101, 3, 23);
    rotate(a);
    int expected2[] = {8, 11, 99, 14, -1, 37, 101, 3, 23, 10};
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected2, a->stack, len, "Input is \"10 8 11 99 14 -1 37 101 3 23\"");
    TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input len is 10");
    free(a->stack);
}

TEST(TestOperations, TestPushToOtherStack)
{
    t_stack *a;
    t_stack *b;
    int     len;

    len = 5;
    a = create_stack(len, len, 1, 2, 3, 4, 5);
    b = create_stack(len, 0); // length of stack b is the same as a, but is has 0 elements inside.
    push_a_to_b(a, b);
    int expected_a_1[] = {2, 3, 4, 5};
    int expected_b_1[] = {1};
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_a_1, a->stack, len - 1, "Input is \"1 2 3 4 5\"");
    TEST_ASSERT_EQUAL_INT_MESSAGE(len - 1, a->num_elements, "Input len is 5");
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_b_1, b->stack, 1, "Input is \"1 2 3 4 5\"");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, b->num_elements, "Input len is 5");

    push_a_to_b(a, b);
    int expected_a_2[] = {3, 4, 5};
    int expected_b_2[] = {2, 1};
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_a_2, a->stack, len - 2, "Input is \"2 3 4 5\"");
    TEST_ASSERT_EQUAL_INT_MESSAGE(len - 2, a->num_elements, "Input len is 4");
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_b_2, b->stack, 2, "Input is \"2 3 4 5\"");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, b->num_elements, "Input len is 4");
    free(a->stack);
    free(b->stack);

    len = 5;
    a = create_stack(len, len, 1, 2, 3, 4, 5);
    b = create_stack(len, 0); // create empty stack b
    push_a_to_b(b, a);
    int expected_a_3[] = {1, 2, 3, 4, 5};
    int expected_b_3[] = {0};
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_a_3, a->stack, len, "Input is \"1 2 3 4 5\"");
    TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input len is 5");
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_b_3, b->stack, 1, "Input is \"1 2 3 4 5\"");
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, b->num_elements, "Input len is 5");
    free(a->stack);
    free(b->stack);
}

TEST(TestOperations, TestRotateAndPush)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	len = 5;
    a = create_stack(len, len, 1, 2, 3, 4, 5);
    b = create_stack(len, 0); // length of stack b is the same as a, but is has 0 elements inside.
	rotate(a); // a = 2 3 4 5 1
	rotate(a); // a = 3 4 5 1 2 
	push_a_to_b(a, b); // a = 4 5 1 2	####	b = 3
	push_a_to_b(a, b); // a = 5 1 2		####	b = 4 3
	rotate(b); // a = 5 1 2		####	b = 3 4
	int	expected_a_1[] = {5, 1, 2};
	int	expected_b_1[] = {3, 4};
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_a_1, a->stack, 3);
	TEST_ASSERT_EQUAL_INT(3, a->num_elements);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_b_1, b->stack, 2);
	TEST_ASSERT_EQUAL_INT(2, b->num_elements);

	push_a_to_b(a, b); // a = 1 2		####	b = 5 3 4
	push_a_to_b(a, b); // a = 2			####	b = 1 5 3 4
	int	expected_a_2[] = {2};
	int	expected_b_2[] = {1, 5, 3, 4};
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_a_2, a->stack, 1);
	TEST_ASSERT_EQUAL_INT(1, a->num_elements);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_b_2, b->stack, 4);
	TEST_ASSERT_EQUAL_INT(4, b->num_elements);

	push_a_to_b(a, b); // a = 			####	b = 2 1 5 3 4
	push_a_to_b(a, b); // a = 			####	b = 2 1 5 3 4
	int	expected_b_3[] = {2, 1, 5, 3, 4};
	TEST_ASSERT_EQUAL_INT(0, a->num_elements);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_b_3, b->stack, 5);
	TEST_ASSERT_EQUAL_INT(5, b->num_elements);

    free(a->stack);
    free(b->stack);
}

TEST(TestOperations, TestSwap)
{
    t_stack *a;
    int     len;

    len = 5;
    a = create_stack(len, len, 1, 2, 3, 4, 5);
	swap(a);
	int expected[] = {2, 1, 3, 4, 5};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected, a->stack, len, "Input is \"1 2 3 4 5\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"1 2 3 4 5\"");
	free(a->stack);

    len = 1;
    a = create_stack(len, len, 1);
	swap(a);
	int expected_1[] = {1};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_1, a->stack, len, "Input is \"1\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"1\"");
	free(a->stack);
}

TEST(TestOperations, TestReverseRotate)
{
    t_stack *a;
    int     len;

    len = 3;
    a = create_stack(len, len, 3, 2, 5);
	reverse_rotate(a);
	int expected[] = {5, 3, 2};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected, a->stack, len, "Input is \"3 2 5\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"3 2 5\"");
	free(a->stack);

    len = 5;
    a = create_stack(len, len, 1, 2, 3, 4, 5);
	reverse_rotate(a);
	int expected_1[] = {5, 1, 2, 3, 4};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_1, a->stack, len, "Input is \"1 2 3 4 5\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"1 2 3 4 5\"");
	free(a->stack);

    len = 5;
    a = create_stack(len, len, 1, 2, 3, 4, 5);
	reverse_rotate(a);
	reverse_rotate(a);
	int expected_2[] = {4, 5, 1, 2, 3};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_2, a->stack, len, "Input is \"1 2 3 4 5\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"1 2 3 4 5\"");
	free(a->stack);

    len = 1;
    a = create_stack(len, len, 1);
	reverse_rotate(a);
	reverse_rotate(a);
	int expected_3[] = {1};
	TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected_3, a->stack, len, "Input is \"1\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(len, a->num_elements, "Input is \"1\"");
	free(a->stack);
}