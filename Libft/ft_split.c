/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:47:50 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/29 15:33:48 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	pt_size(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*set_word(char const *s, size_t *i, char c)
{
	size_t	length;
	size_t	start;
	char	*word;

	length = 0;
	start = *i;
	while (s[start + length] && s[length + start] != c)
		length++;
	word = malloc(length + 1);
	if (word == NULL)
		return (NULL);
	start = 0;
	while (s[*i] != c && s[*i])
	{
		word[start] = s[*i];
		(*i)++;
		start++;
	}
	word[start] = '\0';
	return (word);
}

static int	fill_words(char const *s, char c, char **str)
{
	size_t	i;
	size_t	d;

	i = 0;
	d = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			str[d] = set_word(s, &i, c);
			if (str[d] == NULL)
			{
				while (d)
					free(str[--d]);
				return (0);
			}
			d++;
		}
	}
	str[d] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	ptrs_size;
	char	**str;

	if (!s)
		return (NULL);
	ptrs_size = pt_size(s, c);
	str = malloc((ptrs_size + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	if (!fill_words(s, c, str))
	{
		free(str);
		return (NULL);
	}
	return (str);
}
