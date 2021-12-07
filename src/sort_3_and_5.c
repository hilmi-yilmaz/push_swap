/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_and_5.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 15:54:25 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 11:11:28 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort_3_and_5.h"

/*
** Return index of min number.
** If multiple same min values, return index of last one.
*/

static int	get_min(t_stack *a)
{
	int	i;
	int	min;
	int	idx;

	i = 1;
	min = a->stack[0];
	idx = 0;
	while (i < a->num_elements)
	{
		if (a->stack[i] <= min)
		{
			min = a->stack[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

static void	get_min_on_top_of_stack(t_stack *a)
{
	int	i;

	i = get_min(a);
	if (i < 3)
	{
		while (i != 0)
		{
			rotate_stack(a);
			i--;
		}
		return ;
	}
	while (i != a->num_elements)
	{
		reverse_rotate(a);
		i++;
	}
}

void	sort_three(t_stack *a)
{
	int	*arr;
	
	arr = a->stack;
	if (arr[0] < arr[1] && arr[1] < arr[2])
		return ;
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] > arr[2])
	{
		swap(a);
		rotate_stack(a);
	}
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		swap(a);
	if (arr[0] < arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
	{
		swap(a);
		rotate_stack(a);
		swap(a);
	}
	if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		rotate_stack(a);
		swap(a);
	}
	if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
		rotate_stack(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	get_min_on_top_of_stack(a);
	push_a_to_b(a, b);
	get_min_on_top_of_stack(a);
	push_a_to_b(a, b);
	sort_three(a);
	push_a_to_b(b, a);
	push_a_to_b(b, a);
}