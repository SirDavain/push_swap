/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:48:25 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/04 09:27:30 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

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
	bool			cheapes;
}				t_node;

// push_swap.c

#endif