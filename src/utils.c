/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 17:38:36 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/14 13:14:07 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Skips plus and minus signs.
** Returns the index of the first digit.
** If not a -, + or digit, err = 1.
*/

int	skip_plus_and_minus_signs(const char *num_str, int *minus, int *err)
{
	int	i;

	i = 0;
	while (num_str[i] != '\0')
	{
		if (num_str[i] == '-')
			*minus += 1;
		else if (ft_isdigit(num_str[i]) != 0)
		{
			*minus = *minus % 2;
			return (i);
		}
		else if (num_str[i] != '+')
		{
			*err = 1;
			return (-1);
		}
		i++;
	}
	return (-1);
}

/*
** Return a copy of array.
*/

int	*copy_array(int *array, int num_elements)
{
	int	i;
	int	*cpy_array;

	i = 0;
	cpy_array = ft_calloc(num_elements, sizeof(*cpy_array));
	if (cpy_array == NULL)
		return (NULL);
	while (i < num_elements)
	{
		cpy_array[i] = array[i];
		i++;
	}
	return (cpy_array);
}

/*
** Check if the data in stack "a" is sorted. 
*/

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

/*
** Print error message and return FAILURE.
*/

int	print_and_return_failure(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	return (FAILURE);
}

/*
** Free data in the arguments and return FAILURE.
*/

int	free_and_return_failure(int *arr_1, int *arr_2, int *arr_3)
{
	free(arr_1);
	free(arr_2);
	free(arr_3);
	return (FAILURE);
}
