/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 23:36:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/14 18:23:23 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Free data in the stacks.
*/

static void	free_stacks(t_stack a, t_stack b)
{
	free(a.stack);
	free(b.stack);
}

/*
** The push_swap program. Sorts and array of number using a set of limited
** instructions.
*/

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (validate_input(argv + 1))
		return (FAILURE);
	if (init_stacks(&a, &b, argv + 1, argc - 1))
		return (FAILURE);
	if (check_if_sorted(&a) == 0)
	{
		free_stacks(a, b);
		return (SUCCES);
	}
	if (argc == 4)
		sort_three(&a);
	else if (argc == 6)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	free_stacks(a, b);
	return (SUCCES);
}
