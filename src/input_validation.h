/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:37:14 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/30 16:22:48 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
# define INPUT_VALIDATION_H

/* Macros */

/* System headers */
# include <unistd.h>
# include <stdio.h>

/* User defined header */
# include "data.h"
# include "../libft/libft.h"
# include "atoi_with_int_overflow_check.h"
# include "sorting_algorithms.h"

/* Data structures */

/* Function prototypes */
int	check_for_wrong_characters(char **argv);
int	check_all_are_integers(char **argv);
int	check_for_duplicates(int *sorted_array, int num_elements);
int	validate_input(int argc, char **argv);

#endif