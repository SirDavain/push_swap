/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:41:01 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/01 09:03:10 by dulrich          ###   ########.fr       */
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
			sa();
		else if (stack_len(a) == 3)
			tiny_sort();
		else
			push_swap();
	}
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

void	free_on_error(t_node **a, char **argv, bool argc_2)
{
	free_stack(a);
	if (argc_2)
		free_matrix(argv);
	ft_printf("Error\n");
	exit(1);
}

// not sure if while-loop is correct... could skip a nbr if first char isn't '-' or '+'
int	is_syntax_error(char *s)
{
	int	i;

	i = 0;
	if (!(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9')))
		return (1);
	if (s[i] == '+' || s[i] == '-' && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
		return (1);
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
	}
	return (0);
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
		last_node = find_last_node();
		last_node->next = node;
		node->prev = last_node;
	}
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