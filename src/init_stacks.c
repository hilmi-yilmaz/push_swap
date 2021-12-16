/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 12:43:09 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/16 11:53:04 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init_stacks.h"

/*
** Allocate memory for both stacks a and b.
** Assign id's.
*/

static int	create_stack_a_and_b(t_stack *a, t_stack *b, int num_elements)
{
	ft_bzero(a, sizeof(*a));
	ft_bzero(b, sizeof(*b));
	a->stack = ft_calloc(num_elements, sizeof(*a->stack));
	if (a->stack == NULL)
		return (print_and_return_failure("Error\n"));
	b->stack = ft_calloc(num_elements, sizeof(*b->stack));
	if (b->stack == NULL)
	{
		free(a->stack);
		return (print_and_return_failure("Error\n"));
	}
	a->id = 'a';
	b->id = 'b';
	return (SUCCES);
}

/*
** Fill stack a with values read from input.
*/

static void	fill_stack_a(t_stack *a, char **argv, int num_elements)
{
	int	i;
	int	err;

	i = 0;
	a->num_elements = num_elements;
	while (i < num_elements)
	{
		a->stack[i] = atoi_with_int_overflow_check(argv[i], &err);
		i++;
	}
}

/*
** Create an index stack which contains [0, 1, 2, ...] till length of a->stack.
*/

t_stack	*create_idx_stack(t_stack *a)
{
	int		i;
	t_stack	*idx;

	i = 0;
	idx = ft_calloc(1, sizeof(*idx));
	if (idx == NULL)
		return (NULL);
	idx->stack = ft_calloc(a->num_elements, sizeof(*idx->stack));
	if (idx->stack == NULL)
	{
		free(idx);
		return (NULL);
	}
	while (i < a->num_elements)
	{
		idx->stack[i] = i;
		i++;
	}
	idx->num_elements = a->num_elements;
	return (idx);
}

/*
** Arange the indeces (non-negative values) so that it represents the same
** sorting als the input.
** This way I can sort an array which contains only 0 and positive values.
*/

void	arange_a_stack_from_idx(t_stack *a, t_stack *idx, int *sorted_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a->num_elements)
	{
		while (j < a->num_elements)
		{
			if (sorted_array[i] == a->stack[j])
			{
				a->stack[j] = i;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(idx->stack);
	free(idx);
}

/*
** Will init stacks a and b.
** It fills a with non-negative values using indeces.
*/

int	init_stacks(t_stack *a, t_stack *b, char **argv, int num_elements)
{
	int		*sorted_array;
	t_stack	*idx;

	if (create_stack_a_and_b(a, b, num_elements))
		return (FAILURE);
	fill_stack_a(a, argv, num_elements);
	sorted_array = copy_array(a->stack, a->num_elements);
	if (sorted_array == NULL)
		return (print_and_return_failure("Error\n"));
	bubble_sort(sorted_array, a->num_elements);
	if (check_for_duplicates(sorted_array, a->num_elements))
		return (free_and_return_failure(a->stack, b->stack, sorted_array));
	idx = create_idx_stack(a);
	if (idx == NULL)
		return (free_and_return_failure(a->stack, b->stack, sorted_array));
	arange_a_stack_from_idx(a, idx, sorted_array);
	free(sorted_array);
	return (SUCCES);
}
