/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algorithms.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 16:32:30 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/29 19:31:44 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_ALGORITHMS_H
# define SORTING_ALGORITHMS_H

/* Macros */

/* System headers */
# include <unistd.h>

/* User defined header */
# include "data.h"
# include "../libft/libft.h"

/* Data structures */

/* Function prototypes */
void	bubble_sort(int *array, int len_array);

#endif