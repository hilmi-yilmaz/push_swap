/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:37:58 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 17:38:24 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"

static int	check_amount_of_arguments(int argc)
{
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (FAILURE);
	}
	return (SUCCES);
}

/*
** Check whether all characters given are a space, digit, plus or minus sign.
*/

int	check_for_wrong_characters(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][j] == '\0')
			return (FAILURE);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != '-' && argv[i][j] != '+' && \
				argv[i][j] != ' ' && ft_isdigit(argv[i][j]) == 0)
			{
				ft_putstr_fd("Error\n", STDOUT_FILENO);
				return (FAILURE);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (SUCCES);
}

int	check_all_are_integers(char **argv)
{
	int	i;
	int	res;
	int	err;

	i = 0;
	res = 0;
	err = 0;
	while (argv[i] != NULL)
	{
		res = atoi_with_int_overflow_check(argv[i], &err);
		if (err == 1)
		{
			ft_putstr_fd("Error\n", STDOUT_FILENO);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCES);
}

int	check_for_duplicates(int *sorted_array, int num_elements)
{
	int	i;

	i = 0;
	if (sorted_array == NULL)
		return (FAILURE);
	while (i < num_elements - 1)
	{
		if (sorted_array[i] == sorted_array[i + 1])
		{
			ft_putstr_fd("Error\n", STDOUT_FILENO);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCES);
}

int	validate_input(int argc, char **argv)
{
	if (check_amount_of_arguments(argc) || \
		check_for_wrong_characters(argv) || \
		check_all_are_integers(argv))
		return (FAILURE);
	return (SUCCES);
}
