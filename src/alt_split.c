/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:38:21 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/14 21:13:09 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char separator)
{
	int		i;
	bool	is_inside_word;

	i = 0;
	while (*str)
	{
		is_inside_word = false;
		while (*str && *str == separator)
			str++;
		while (*str && *str != separator)
		{
			if (!is_inside_word)
			{
				i++;
				is_inside_word = true;
			}
			str++;
		}
	}
	return (i);
}

static char	*get_next_word(char *str, char separator)
{
	static int	index = 0;
	int			i;
	int			len;
	char		*next_str;

	i = 0;
	len = 0;
	while (str[index] == separator)
		index++;
	while (str[index + len] && (str[index + len] != separator))
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while (str[index] && (str[index] != separator))
		next_str[i++] = str[index++];
	next_str[i] = '\0';
	return (next_str);
}

char	**alt_split(char *str, char separator)
{
	int		nbr_of_words;
	char	**arr_of_str;
	int		i;

	i = 0;
	nbr_of_words = count_words(str, separator);
	if (!nbr_of_words)
		exit(1);
	arr_of_str = malloc(sizeof(char *) * (size_t)(nbr_of_words + 2));
	if (!arr_of_str)
		return (NULL);
	while (nbr_of_words-- >= 0)
	{
		if (i == 0)
		{
			arr_of_str[i] = malloc(sizeof(char));
			if (arr_of_str[i] == NULL)
				return (NULL);
			arr_of_str[i++][0] = '\0';
			continue ;
		}
		arr_of_str[i++] = get_next_word(str, separator);
	}
	arr_of_str[i] = NULL;
	return (arr_of_str);
}
