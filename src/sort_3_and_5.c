/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_and_5.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 15:54:25 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/06 17:54:17 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort_3_and_5.h"

/*
** Return index of max number
*/
// static int	get_max(t_stack *a)
// {
// 	int	i;
// 	int	max;

// 	i = 0;
// 	max = 0;
// 	while (i < a->num_elements)
// 	{
// 		if (a->stack[i] > max)
// 			max = i;
// 		i++;
// 	}
// 	return (max);
// }

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

// void	sort_five(t_stack *a, t_stack *b)
// {
// 	int	i;

// 	i = 0;

// }