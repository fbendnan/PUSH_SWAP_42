/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:44:00 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/27 00:44:01 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	size_t	ft_count_words(const char *s, char c)
{
	short	inside_word;
	size_t	words;

	words = 0;
	while (*s)
	{
		inside_word = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				words++;
				inside_word = 1;
			}
			s++;
		}
	}
	return (words);
}

static int	safe_malloc(char **str, size_t position, size_t len)
{
	size_t	i;

	i = 0;
	str[position] = malloc(len + 1);
	if (!(str[position]))
	{
		while (position > i)
		{
			free(str[i]);
			i++;
		}
		free(str);
		return (0);
	}
	return (1);
}

static	char	**ft_fill(char **str, const char *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_malloc(str, i, len))
				ft_strlcpy(str[i], s - len, len + 1);
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_num;
	char	**str;

	if (!s)
		return (NULL);
	words_num = ft_count_words(s, c);
	str = malloc((words_num + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	ft_fill(str, s, c);
	return (str);
}