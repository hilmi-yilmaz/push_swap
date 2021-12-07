/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stacks.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 12:43:25 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 13:39:44 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_STACKS_H
# define INIT_STACKS_H

/* System headers */
# include <stdlib.h>

/* User defined header */
# include "data.h"
# include "../libft/libft.h"
# include "atoi_with_int_overflow_check.h"
# include "sorting_algorithms.h"
# include "input_validation.h"

/* Function prototypes */
void	arange_idx_stack(t_stack *a, t_stack *idx, int *sorted_array);
t_stack	*create_idx_stack(t_stack *a);
t_stack	*init_stacks(t_stack *a, t_stack *b, char **argv, int num_elements);

#endif