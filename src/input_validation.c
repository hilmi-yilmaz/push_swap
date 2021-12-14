/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:37:58 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/14 18:23:03 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"

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
			return (print_and_return_failure("Error\n"));
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != '-' && argv[i][j] != '+' && \
				argv[i][j] != ' ' && ft_isdigit(argv[i][j]) == 0)
				return (print_and_return_failure("Error\n"));
			j++;
		}
		j = 0;
		i++;
	}
	return (SUCCES);
}

/*
** Check that all numbers given are in the range of integers (no overflows).
*/

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
			return (print_and_return_failure("Error\n"));
		i++;
	}
	return (SUCCES);
}

/*
** Check for duplicates in the input using the sorted array.
*/

int	check_for_duplicates(int *sorted_array, int num_elements)
{
	int	i;

	i = 0;
	if (sorted_array == NULL)
		return (FAILURE);
	while (i < num_elements - 1)
	{
		if (sorted_array[i] == sorted_array[i + 1])
			return (print_and_return_failure("Error\n"));
		i++;
	}
	return (SUCCES);
}

/*
** Validate the input by checking:
** 1: amount of arguments given.
** 2: wrong characters.
** 3: numbers are in integer range.
** The check for duplicates is done in init_stacks.c,
** after the data is sorted.
*/

int	validate_input(char **argv)
{
	if (check_for_wrong_characters(argv) || \
		check_all_are_integers(argv))
		return (FAILURE);
	return (SUCCES);
}
