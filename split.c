/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:23:56 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/25 00:24:36 by fbendnan         ###   ########.fr       */
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

static int	set_nt_in_first_pos(size_t *i, char **str)
{
	str[0] = malloc(1);
	if (!str[0])
		return (0);
	str[0][0] = '\0';
    *i = 1;
    return (1);
}

static	char	**ft_fill(char **str, const char *s, char c)
{
	size_t	len;
	size_t	i;
    
	i = 0;
	while (*s)
	{
        if(i == 0 && !set_nt_in_first_pos(&i, str))
            return ((free(str)),  (NULL));
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
			if (!safe_malloc(str, i, len))
                return (NULL);
            ft_strlcpy(str[i], s - len, len + 1);
			i++;
		}
	}
	return ((str[i] = NULL),  str);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_num;
	char	**str;

	if (!s)
		return (NULL);
	words_num = ft_count_words(s, c);
	str = malloc((words_num + 2) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_fill(str, s, c);
	return (str);
}