/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 12:33:54 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/06 17:38:30 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"

// static void	print_stack(t_stack *a)
// {
// 	int	i;

// 	i = 0;
// 	while (i < a->num_elements)
// 	{
// 		printf("%d ", a->stack[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

void	radix_sort(t_stack *a, t_stack *b)
{
	size_t	bit;
	int		number_in_stack;
	int		total_elements;

	bit = 0;
	number_in_stack = 0;
	total_elements = a->num_elements;
	while (check_if_sorted(a) == FAILURE)
	{
		while (number_in_stack < total_elements)
		{
			if ((a->stack[0] & (0b01 << bit)) == 0)
				push_a_to_b(a, b);
			else
				rotate_stack(a);
			number_in_stack++;
		}
		while (b->num_elements != 0)
			push_a_to_b(b, a);
		number_in_stack = 0;
		bit++;
	}
}
