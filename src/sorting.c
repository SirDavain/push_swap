/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:01:39 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/21 22:08:23 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	tiny_sort(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_biggest(*a);
	if (*a == biggest_node)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	handle_five(t_node **a, t_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rot(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}

void	push_swap_helper(t_node *smallest, t_node **a)
{
	if (smallest->above_median)
	{
		while (*a != smallest)
			ra(a, false);
	}
	else
	{
		while (*a != smallest)
			rra(a, false);
	}
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;
	int		len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_pos(*a);
	smallest = find_smallest(*a);
	push_swap_helper(smallest, a);
}
