/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 10:52:18 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/06 18:32:02 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** Return when total elements in stack a are either 0 or 1 (nothing to rotate).
** Save first element, move the rest to the left,
** set last element as saved first element.
*/

void	rotate_stack(t_stack *a)
{
	int	i;
	int	tmp;

	if (a->num_elements < 2)
	    return ;
	i = 0;
	tmp = a->stack[0];
	while (i < a->num_elements - 1)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = tmp;
	//ft_putstr_fd("rr\n", 1);
}

/*
** Return if no elements in stack a, so nothing to push.
** Shift elements of b to the right (make space for new element).
** Push element from a to b.
** Move all elements from a back to the left (to the top of the stack).
*/

void	push_a_to_b(t_stack *a, t_stack *b)
{
	int	i;

	if (a->num_elements == 0)
		return ;
	i = b->num_elements;
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i--;
	}
	b->stack[0] = a->stack[0];
	b->num_elements += 1;
	i = 1;
	while (i < a->num_elements)
	{
		a->stack[i - 1] = a->stack[i];
		i++;
	}
	a->num_elements -= 1;
	//ft_putstr_fd("push\n", 1);
}

void	swap(t_stack *a)
{
	int	tmp;

	if (a->num_elements < 2)
		return ;
	tmp = a->stack[0];
	a->stack[0] = a->stack[1];
	a->stack[1] = tmp;
}

void	reverse_rotate(t_stack *a)
{
	int	i;
	int	tmp;

	if (a->num_elements < 2)
		return ;
	i = a->num_elements - 1;
	tmp = a->stack[a->num_elements - 1];
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = tmp;
}