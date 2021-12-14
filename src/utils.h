/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 17:38:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/14 13:15:00 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* System headers */
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/* User defined header */
# include "data.h"
# include "../libft/libft.h"

/* Function prototypes */
int	skip_plus_and_minus_signs(const char *num_str, int *minus, int *err);
int	*copy_array(int *array, int num_elements);
int	check_if_sorted(t_stack *a);
int	print_and_return_failure(char *str);
int	free_and_return_failure(int *arr_1, int *arr_2, int *arr_3);

#endif