/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 17:38:36 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/06 17:38:48 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_if_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->num_elements - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (FAILURE);
		i++;
	}
	return (SUCCES);
}