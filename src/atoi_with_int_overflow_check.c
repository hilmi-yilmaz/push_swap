/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_with_int_overflow_check.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:05:34 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/27 16:21:35 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "atoi_with_int_overflow_check.h"

int	atoi_with_int_overflow_check(const char *num_str)
{
	int	i;
	int	result;
	int	num_len;

	i = 0;
	result = 0;
	num_len = strlen(num_str);
	while (i < num_len)
	{
		result = result * 10 + (num_str[i] - '0'); 
		i++;
	}
	return (result);
}