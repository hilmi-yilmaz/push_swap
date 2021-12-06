/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 23:36:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/01 18:46:36 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;
	t_stack	*idx;

	if (validate_input(argc, argv + 1))
		return (FAILURE);
	idx = init_stacks(&a, &b, argv + 1, argc - 1);
	if (idx == NULL)
		return (FAILURE);
	return (SUCCES);
}