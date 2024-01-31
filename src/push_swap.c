/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:41:01 by dulrich           #+#    #+#             */
/*   Updated: 2024/01/30 17:16:25 by dulrich          ###   ########.fr       */
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
}

long	ft_atol(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	return (result * sign);
}

void	create_stack(t_node **a, char **argv, bool argc_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error)
			free_func();
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_func();
		append_node();
		i++;
	}
	if (argc_2)
		free_matrix(argv);
}

int	stack_is_sorted()
{
	
}