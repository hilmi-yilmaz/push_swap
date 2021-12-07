/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 17:38:36 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 18:08:18 by hyilmaz       ########   odam.nl         */
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
