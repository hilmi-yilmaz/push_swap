/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_and_5.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 15:54:25 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 17:40:15 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort_3_and_5.h"

/*
** Return index of min number.
** If multiple same min values, return index of last one.
*/

static int	get_min(t_stack *a, int dont_check_idx)
{
	int	i;
	int	min;
	int	idx;

	i = 1;
	min = a->stack[0];
	idx = 0;
	while (i < a->num_elements)
	{
		if (a->stack[i] <= min && i != dont_check_idx)
		{
			min = a->stack[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

/*
** Moves the idx to the top of the stack.
*/

static void	get_idx_on_top_of_stack(t_stack *a, int idx)
{
	if (idx < 3)
	{
		while (idx != 0)
		{
			rotate(a);
			idx--;
		}
		return ;
	}
	while (idx != a->num_elements)
	{
		reverse_rotate(a);
		idx++;
	}
}

/*
** Returns the idx of the 2 minimal elements 
** which gets to the top of a the fastest.
*/

static int	which_idx_gets_faster_on_top(t_stack *a)
{
	int	min_idx_1;
	int	min_idx_2;
	int	shortest_path_1;
	int	shortest_path_2;

	min_idx_1 = get_min(a, -1);
	min_idx_2 = get_min(a, min_idx_1);
	if (min_idx_1 < 3)
		shortest_path_1 = min_idx_1;
	else
		shortest_path_1 = 4 - min_idx_1 + 1;
	if (min_idx_2 < 3)
		shortest_path_2 = min_idx_2;
	else
		shortest_path_2 = 4 - min_idx_2 + 1;
	if (shortest_path_1 < shortest_path_2)
		return (min_idx_1);
	else
		return (min_idx_2);
}

/*
** Hardcoded sort of 3 elements.
*/

void	sort_three(t_stack *a)
{
	int	*arr;

	arr = a->stack;
	if (arr[0] < arr[1] && arr[1] < arr[2])
		return ;
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] > arr[2])
	{
		swap(a);
		rotate(a);
	}
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		swap(a);
	if (arr[0] < arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
	{
		swap(a);
		rotate(a);
		swap(a);
	}
	if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		rotate(a);
		swap(a);
	}
	if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
		rotate(a);
}

/*
** Sort 5 elements. Push 2 smallest values to, use three_sort on a,
** push elements of b back to a.
*/

void	sort_five(t_stack *a, t_stack *b)
{
	int	idx_shortest_path_to_top;

	idx_shortest_path_to_top = which_idx_gets_faster_on_top(a);
	get_idx_on_top_of_stack(a, idx_shortest_path_to_top);
	push_a_to_b(a, b);
	get_idx_on_top_of_stack(a, get_min(a, -1));
	push_a_to_b(a, b);
	sort_three(a);
	if (b->stack[0] < b->stack[1])
		swap(b);
	push_a_to_b(b, a);
	push_a_to_b(b, a);
}
