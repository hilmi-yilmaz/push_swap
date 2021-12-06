/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 10:37:21 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/06 11:22:02 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

/* Macros */

/* System headers */
# include <stdio.h>

/* User defined header */
# include "data.h"

/* Data structures */

/* Function prototypes */
void    rotate_stack(t_stack *a);
void    push_a_to_b(t_stack *a, t_stack *b);

#endif