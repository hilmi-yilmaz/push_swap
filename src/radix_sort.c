/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 12:33:54 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/14 13:35:48 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"

/*
** Sort data using two stack a and b.
** Loop over the bits and put 0 bits in stack b.
** Then move all back to top of a.
** Continue with next bit.
*/

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
				rotate(a);
			number_in_stack++;
		}
		while (b->num_elements != 0)
			push_a_to_b(b, a);
		number_in_stack = 0;
		bit++;
	}
}
