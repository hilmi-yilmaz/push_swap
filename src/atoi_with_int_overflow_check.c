/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_with_int_overflow_check.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:05:34 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/28 18:50:53 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "atoi_with_int_overflow_check.h"

/*
** Skips plus and minus signs.
** Returns the index of the first digit.
** If not a -, + or digit, err = 1.
*/

static int	skip_plus_and_minus_signs(const char *num_str, int *minus, int *err)
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
** Skips all characters until first digit.
*/

static int	skip_until_first_digit(const char *num_str, t_atoi *data, int *i)
{
	int	ret;

	*i += skip_chr_func_pointer((char *)num_str, ft_isspace);
	ret = skip_plus_and_minus_signs(num_str + *i, &data->minus, data->err);
	if (ret == -1)
		return (FAILURE);
	*i += ret;
	*i += skip_chr((char *)num_str, '0');
	return (SUCCES);
}

/*
** Inits data.
** Skips all characters until first digit.
*/
static int	init_atoi_process(const char *num_str, t_atoi *data, \
								int *err, int *i)
{
	data->result = 0;
	data->minus = 0;
	data->err = err;
	*data->err = 0;
	if (num_str == NULL)
	{
		*err = 1;
		return (FAILURE);
	}
	skip_until_first_digit(num_str, data, i);
	return (SUCCES);
}

/*
** Checks for digits.
** If something other than a digit is encountered,returns a failure.
*/

static int	check_for_digit(const char *num_str, t_atoi data, int i, int j)
{
	if (j == 0 && ft_isdigit(num_str[i]) == 0)
	{
		*data.err = 1;
		return (FAILURE);
	}
	else if (j != 0 && ft_isdigit(num_str[i]) == 0)
		return (SUCCES + 2);
	return (SUCCES);
}

/*
** Handles integer overflow. It look at MAX_INT / 10 and
** checks the digits that needs to be added to the result.
*/

static int	handle_overflow(t_atoi *data, const char *num_str, int i, int j)
{
	if (j > 9)
	{
		*data->err = 1;
		return (FAILURE);
	}
	else if (j == 9 && data->result > (INT_MAX / 10))
	{
		*data->err = 1;
		return (FAILURE);
	}
	else if (j == 9 && data->result == (INT_MAX / 10))
	{
		if (num_str[i] > '7')
		{
			if ((num_str[i] >= '8' && (data->minus == 0)) || \
				(num_str[i] > '8' && (data->minus != 0)))
			{
				*data->err = 1;
				return (FAILURE);
			}
		}
	}
	return (SUCCES);
}

/*
** Tranlates string-representation of integer to an actual integer.
** err is set to 1 if integer under- or overflow happens, 0 on success.
** integer is returned. If err = 1, 
** this integer is created by undefined behaviour.
*/

int	atoi_with_int_overflow_check(const char *num_str, int *err)
{
	int		i;
	int		j;
	int		ret;
	t_atoi	data;

	i = 0;
	j = 0;
	if (init_atoi_process(num_str, &data, err, &i))
		return (FAILURE);
	while (num_str[i] != '\0')
	{
		ret = check_for_digit(num_str, data, i, j);
		if (ret == SUCCES + 2)
			break ;
		else if (ret == FAILURE)
			return (FAILURE);
		if (handle_overflow(&data, num_str, i, j))
			return (FAILURE);
		data.result = data.result * 10 + (num_str[i] - '0');
		i++;
		j++;
	}
	if (data.minus != 0)
		data.result *= -1;
	return (data.result);
}

// int	main(void)
// {
// 	int	res;
// 	int	err = 0;

// 	res = atoi_with_int_overflow_check("1a467", &err);
// 	printf("%d\n%d\n", res, err);
// 	return (0);
// }