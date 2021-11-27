/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_with_int_overflow_check.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:05:34 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/27 21:43:48 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "atoi_with_int_overflow_check.h"

static int	skip_plus_and_minus_signs(const char *num_str, int *minus)
{
	int	i;

	i = 0;
	while (num_str[i] != '\0')
	{
		if (num_str[i] == '-')
			*minus += 1;
		else if (ft_isdigit(num_str[i]) != 0)
			return (i);
		else if (num_str[i] != '+')
			return (-1);
		i++;
	}
	return (-1);
}

/*
** Tranlates string-representation of integer to an actual integer.
** err is set to 1 if integer under- or overflow happens, 0 on success.
** integer is returned. If err = 1, this integer is created by undefined behaviour.
*/

int	atoi_with_int_overflow_check(const char *num_str, int *err)
{
	int	i;
	int	j;
	int	result;
	int	minus;
	int	ret;

	i = 0;
	j = 0;
	result = 0;
	minus = 0;
	if (num_str == NULL)
	{
		*err = 1;
		return (result);	
	}
	i += skip_chr((char *)num_str, ft_isspace);
	ret = skip_plus_and_minus_signs(num_str + i, &minus);
	if (ret == -1)
	{
		*err = 1;
		return (-1);
	}
	i += ret;
	while (num_str[i] != '\0')
	{
		if (j == 0 && ft_isdigit(num_str[i]) == 0)
		{
			*err = 1;
			return (result);
		}
		else if (j != 0 && ft_isdigit(num_str[i]) == 0)
			break ;
		if (j > 9)
		{
			*err = 1;
			return (result);
		}
		if (j == 9 && result > (INT_MAX / 10))
		{
			// overflow
			*err = 1;
			return (result);
		}
		else if (j == 9 && result == (INT_MAX / 10))
		{
			if (num_str[i] > '7')
			{
				if (num_str[i] == '8' && (minus % 2 != 0))
				{
					result = result * 10 + (num_str[i] - '0');
					i++;
					j++;
					continue ;
				}
				// overflow
				*err = 1;
				return (result);
			}
		}
		else if (j == 9 && result < (INT_MAX / 10))
		{
			result = result * 10 + (num_str[i] - '0');
			i++;
			j++;
			continue ;
		}
		result = result * 10 + (num_str[i] - '0');
		i++;
		j++;
	}
	if (minus % 2 != 0)
		result *= -1;
	*err = 0;
	return (result);
}

// int	main(void)
// {
// 	int	res;
// 	int	err = 0;

// 	res = atoi_with_int_overflow_check(" +a1467", &err);
// 	printf("%d\n%d\n", res, err);
// 	return (0);
// }