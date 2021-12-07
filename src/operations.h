/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 10:37:21 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 13:38:10 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

/* System headers */
# include <unistd.h>

/* User defined header */
# include "data.h"
# include "../libft/libft.h"

/* Function prototypes */
void    rotate(t_stack *a);
void    push_a_to_b(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	reverse_rotate(t_stack *a);

#endif