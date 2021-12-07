/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_with_int_overflow_check.h                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:02:38 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 17:56:39 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_WITH_INT_OVERFLOW_CHECK_H
# define ATOI_WITH_INT_OVERFLOW_CHECK_H

/* System headers */
# include <limits.h>

/* User defined header */
# include "data.h"
# include "../libft/libft.h"
# include "utils.h"

/* Data structures */
typedef struct s_atoi
{
	int	result;
	int	minus;
	int	*err;
}				t_atoi;

/* Function prototypes */
int	atoi_with_int_overflow_check(const char *num_str, int *err);

#endif