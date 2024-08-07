/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:23:37 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/05 18:34:07 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_artificial_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_links(t_link **stack)
{
	t_link	*tmp;

	if (stack == NULL)
		return ;
	tmp = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	print_stack(t_link *stack, char *name)
{
	printf("Stack %s: ", name);
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}
