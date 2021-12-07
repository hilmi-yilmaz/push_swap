/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_and_5.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 15:53:32 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 10:45:38 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_3_AND_5_H
# define SORT_3_AND_5_H

/* Macros */

/* System headers */

/* User defined header */
# include "data.h"
# include "operations.h"
# include "utils.h"

/* Data structures */

/* Function prototypes */
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

#endif