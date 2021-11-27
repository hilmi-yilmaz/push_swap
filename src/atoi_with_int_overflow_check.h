/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_with_int_overflow_check.h                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 14:02:38 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/27 16:16:43 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_WITH_INT_OVERFLOW_CHECK_H
# define ATOI_WITH_INT_OVERFLOW_CHECK_H

/* Macros */

/* System headers */
# include <stddef.h>
# include <string.h>

/* User defined header */
# include "data.h"

/* Data structures */

/* Function prototypes */
int	atoi_with_int_overflow_check(const char *num_str);

#endif