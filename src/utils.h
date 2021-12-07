/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 17:38:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 18:07:31 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* System headers */
# include <stddef.h>

/* User defined header */
# include "data.h"
# include "../libft/libft.h"

/* Function prototypes */
int	skip_plus_and_minus_signs(const char *num_str, int *minus, int *err);
int	*copy_array(int *array, int num_elements);
int	check_if_sorted(t_stack *a);

#endif