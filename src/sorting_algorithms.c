/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algorithms.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 16:32:14 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/14 13:31:51 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_algorithms.h"

/*
** Sort algorithms by comparing and swapping values next to each other.
** The bigger number flow like bubble to the top of the array.
*/

void	bubble_sort(int *array, int len_array)
{
	int	i;
	int	j;
	int	len_array_variable;
	int	tmp;

	i = 0;
	j = 0;
	len_array_variable = len_array;
	while (i < len_array - 1)
	{
		while (j < len_array_variable - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
		len_array_variable--;
	}
}
