/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 12:23:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/06 17:54:08 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_SORT_H
# define RADIX_SORT_H

/* Macros */

/* System headers */

/* User defined header */
# include "data.h"
# include "operations.h"
# include "utils.h"

/* Data structures */

/* Function prototypes */
void	radix_sort(t_stack *a, t_stack *b);

#endif