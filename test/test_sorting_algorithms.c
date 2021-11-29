/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_sorting_algorithms.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 16:50:23 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/29 23:38:33 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "../src/sorting_algorithms.h"

#include <stdlib.h>
#include <time.h>
#include <limits.h>

static int	*generate_array(int num_elements, int min, int max)
{
	int	i;
	int	*array;
	
	i = 0;
	array = calloc(num_elements, sizeof(*array));
	srand((unsigned int)time(NULL));
	while (i < num_elements)
	{
		array[i] = rand() % (max-min) + min;
		i++;
	}
	return (array);
}

static int	*copy_array(int *array, int num_elements)
{
	int	i;
	int	*copy_array;
	
	i = 0;
	copy_array = calloc(num_elements, sizeof(*copy_array));
	while (i < num_elements)
	{
		copy_array[i] = array[i];
		i++;
	}
	return (copy_array);
}

static int	comp(const void *a, const void *b)
{
	int	*x;
	int	*y;
	
	x = (int *) a;
	y = (int *) b;
	return (*x - *y);
}

/*
static void	print_array(int *array, int num_elements)
{
	int	i;

	i = 0;
	while (i < num_elements)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}
*/

static int	*array;
static int	*sorted_array;

TEST_GROUP(TestSortingAlgorithms);

TEST_SETUP(TestSortingAlgorithms)
{
}

TEST_TEAR_DOWN(TestSortingAlgorithms)
{
}

TEST(TestSortingAlgorithms, BubbleSort)
{
	unsigned int	len;
	
	/* Test case 1 */
	len = 10;
	array = generate_array(len, -1000, 1000);
	sorted_array = copy_array(array, len);
	bubble_sort(array, len);
	qsort(sorted_array, len, sizeof(*sorted_array), comp);
	TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, len);
	free(array);
	free(sorted_array);

	/* Test case 2 */
	len = 10000;
	array = generate_array(len, INT_MIN, INT_MAX);
	sorted_array = copy_array(array, len);
	bubble_sort(array, len);
	qsort(sorted_array, len, sizeof(*sorted_array), comp);
	TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, len);
	free(array);
	free(sorted_array);
}