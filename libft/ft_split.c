/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:26:31 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/28 21:58:11 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		len = 0;
// 	else if (start + len > ft_strlen(s))
// 		len = ft_strlen(s) - start;
// 	substr = (char *)malloc((len + 1) * sizeof(char));
// 	if (!substr)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		substr[i] = s[start + i];
// 		i++;
// 	}
// 	substr[i] = '\0';
// 	return (substr);
// }

static int	ft_count(const char *s, int c)
{
	int	i;
	int	num_of_str;

	if (!s)
		return (0);
	i = 0;
	num_of_str = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			num_of_str++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	if (num_of_str < 2)
		exit (0);
	return (num_of_str);
}

static void	ft_free_split(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	*ft_get_next_substr(const char **s, char c)
{
	const char	*start;
	const char	*end;
	size_t		len;
	char		*substr;

	start = *s;
	while (*start && *start == c)
		start++;
	end = start;
	while (*end && *end != c)
		end++;
	len = end - start;
	substr = ft_substr(start, 0, len);
	*s = end;
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		i;
	int		num_of_str;

	if (!s)
		return (NULL);
	num_of_str = ft_count(s, c);
	str_arr = (char **)malloc((num_of_str + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	i = 0;
	while (num_of_str > 0)
	{
		str_arr[i] = ft_get_next_substr(&s, c);
		if (!str_arr[i])
		{
			ft_free_split(str_arr);
			return (NULL);
		}
		i++;
		num_of_str--;
	}
	str_arr[i] = NULL;
	return (str_arr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char c = ' ';
// 	char *s = " Hippo po ta mus ";
// 	char **result;

// 	result = ft_split(s, c);
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("%s", result[i]);
// 		i++;
// 	}
// 	ft_free_split(result);
// 	return (0);
// }