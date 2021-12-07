/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 23:36:03 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/07 13:34:53 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

/* Macros */
# define SUCCES 0
# define FAILURE 1

/* Data structures */
typedef struct s_stack
{
	int		*stack;
	int		num_elements;
	char	id;
}				t_stack;

#endif