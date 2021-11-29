/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 23:36:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/30 00:39:53 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	if (validate_input(argc, argv + 1))
		return (FAILURE);
	return (SUCCES);
}