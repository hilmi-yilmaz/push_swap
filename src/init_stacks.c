/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 12:43:09 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/11/30 21:30:24 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init_stacks.h"

static int	*copy_array(int *array, int num_elements)
{
	int	i;
	int	*copy_array;
	
	i = 0;
	copy_array = ft_calloc(num_elements, sizeof(*copy_array));
	while (i < num_elements)
	{
		copy_array[i] = array[i];
		i++;
	}
	return (copy_array);
}

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
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (FAILURE);
	}
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
	idx->stack = ft_calloc(a->num_elements, sizeof(*idx->stack));
	while (i < a->num_elements)
	{
		idx->stack[i] = i;
		i++;
	}
	idx->num_elements = a->num_elements;
	return (idx);
}

void	arange_idx_stack(t_stack *a, t_stack *idx, int *sorted_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a->num_elements)
	{
		while (j < a->num_elements)
		{
			if (i != j && sorted_array[i] == a->stack[j])
			{
				idx->stack[j] = i;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/*
** Will init stacks a and b.
** Returns a pointer to a new stack with indeces.
*/

t_stack	*init_stacks(t_stack *a, t_stack *b, char **argv, int num_elements)
{
	int		*sorted_array;
	t_stack *idx;
	
	create_stack_a_and_b(a, b, num_elements);
	fill_stack_a(a, argv, num_elements);
	sorted_array = copy_array(a->stack, a->num_elements);
	bubble_sort(sorted_array, a->num_elements);
	if (check_for_duplicates(sorted_array, a->num_elements))
	{
		free(sorted_array);
		return (NULL);
	}
	idx = create_idx_stack(a);
	arange_idx_stack(a, idx, sorted_array);
	free(sorted_array);
	return (idx);
}