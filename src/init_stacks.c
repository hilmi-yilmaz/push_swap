/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 12:43:09 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/12/14 11:13:11 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init_stacks.h"

static int	create_stack_a_and_b(t_stack *a, t_stack *b, int num_elements)
{
	ft_bzero(a, sizeof(*a));
	ft_bzero(b, sizeof(*b));
	a->stack = ft_calloc(num_elements, sizeof(*a->stack));
	if (a->stack == NULL)
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (FAILURE);
	}
	b->stack = ft_calloc(num_elements, sizeof(*b->stack));
	if (b->stack == NULL)
	{
		free(a->stack);
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (FAILURE);
	}
	a->id = 'a';
	b->id = 'b';
	return (SUCCES);
}

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
	free(idx);
}

/*
** Will init stacks a and b.
** Returns a pointer to a new stack with indeces.
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
		return (FAILURE);
	bubble_sort(sorted_array, a->num_elements);
	if (check_for_duplicates(sorted_array, a->num_elements))
	{
		free(sorted_array);
		return (FAILURE);
	}
	idx = create_idx_stack(a);
	if (idx == NULL)
	{
		free(sorted_array);
		return (FAILURE);
	}
	arange_a_stack_from_idx(a, idx, sorted_array);
	free(sorted_array);
	return (SUCCES);
}
