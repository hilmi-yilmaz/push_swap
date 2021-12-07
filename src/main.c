/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 23:36:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 14:53:55 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	if (validate_input(argc, argv + 1))
		return (FAILURE);
	if (init_stacks(&a, &b, argv + 1, argc - 1))
		return (FAILURE);
	if (argc == 4)
		sort_three(&a);
	else if (argc == 6)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	return (SUCCES);
}