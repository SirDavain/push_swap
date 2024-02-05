/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:27:35 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/03 09:28:16 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
