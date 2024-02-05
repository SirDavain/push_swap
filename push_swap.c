/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:41:01 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/04 10:14:54 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	create_stack(&a, argv + 1, argc == 2);
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack();
}

void	create_stack(t_node **a, char **argv, bool argc_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (is_syntax_error(argv[i]))
			free_on_error(a, argv[i], argc_2);
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_on_error(a, argv[i], argc_2);
		append_node(a, (int)n);
		i++;
	}
	if (argc_2)
		free_matrix(argv);
}

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	append_node(t_node **stack, int	n)
{
	t_node	*node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->next == NULL;
	node->value = n;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_node	*find_smallest(t_node *stack)
{
	t_node	*smallest_node;
	long	smallest;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

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

int	stack_len(t_node *stack)
{
	int	len;
	
	if (stack == NULL)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_node	*find_biggest(t_node *stack)
{
	t_node	*biggest_node;
	int		biggest;

	if (stack == NULL)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

t_node	*find_last(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	set_pos(t_node *stack)
{
	int	i;
	int	middle;

	if (stack == NULL)
		return ;
	i = 0;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= middle)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	find_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->price = b->pos;
		if (!(b->above_median))
			b->price = len_b - (b->pos);
		if (b->target->above_median)
			b->price += b->target->pos;
		else
			b->price += len_a - (b->target->pos);
		b = b->next;
	}
}

void	set_cheapest(t_node *b)
{
	long	best_value;
	t_node	*best_match_node;

	if (b == NULL)
		return (NULL);
	best_value = LONG_MAX;
	while (b)
	{
		
	}
}

void	set_target(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match = LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_nodes(t_node *a, t_node *b)
{
	set_pos(a);
	set_pos(b);
	set_target(a, b);
	find_price(a, b);
	set_cheapest(b);
}

void	tiny_sort(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_biggest(*a);
	if (*a = biggest_node)
		ra(a, false);
	else if ((*a)->next = biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	handle_five(t_node **a, t_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rot(a, find_lowest(*a), 'a');
		pb(b, a, false);
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
		
	}
}