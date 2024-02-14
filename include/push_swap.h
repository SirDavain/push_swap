/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:48:25 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/14 21:07:19 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
	int				pos;
	int				value;
	int				fin_index;
	int				price;
	bool			above_median;
	bool			cheapest;
}				t_node;

// push_swap.c
int		main(int argc, char **argv);
void	create_stack(t_node **a, char **argv, bool argc_2);
void	finish_rot(t_node **stack, t_node *top, char stack_name);

// ps_error.c
void	free_on_error(t_node **a, char **argv, bool argc_2);
int		is_syntax_error(char *s);
void	free_stack(t_node **stack);

// utils.c
long	ft_atol(const char *str);
void	free_matrix(char **argv);
int		stack_len(t_node *stack);
t_node	*get_cheapest(t_node *stack);

// swap.c
void	swap(t_node **head);
void	sa(t_node **a, bool checker);
void	sb(t_node **b, bool checker);
void	ss(t_node **a, t_node **b, bool checker);

// push.c
void	push(t_node **dest, t_node **src);
void	pa(t_node **a, t_node **b, bool checker);
void	pb(t_node **b, t_node **a, bool checker);

// rotate.c
void	rotate(t_node **stack);
void	ra(t_node **a, bool checker);
void	rb(t_node **b, bool checker);
void	rr(t_node **a, t_node **b, bool checker);
void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node);

// rev_rotate.c
void	rev_rotate(t_node **stack);
void	rra(t_node **a, bool checker);
void	rrb(t_node **b, bool checker);
void	rrr(t_node **a, t_node **b, bool checker);
void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node);

// find.c
t_node	*find_smallest(t_node *stack);
t_node	*find_biggest(t_node *stack);
t_node	*find_last(t_node *head);
void	find_price(t_node *a, t_node *b);

// nodes.c
void	init_nodes(t_node *a, t_node *b);
void	move_nodes(t_node **a, t_node **b);
void	append_node(t_node **stack, int	n);

// set.c
void	set_pos(t_node *stack);
void	set_to_cheapest(t_node *b);
void	set_target(t_node *a, t_node *b);

// sorting.c
int		stack_is_sorted(t_node *stack);
void	tiny_sort(t_node **a);
void	handle_five(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);

// alt_split.c
char	**alt_split(char *str, char separator);

#endif