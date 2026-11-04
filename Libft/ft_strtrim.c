/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:48:47 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/30 21:05:20 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_str(size_t end, size_t start, const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(end - start + 2);
	if (str == NULL)
		return (NULL);
	while (end >= start && s1[start])
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static void	end_str(size_t *end, char const *set, const char *s1)
{
	size_t	i;

	i = 0;
	while (*end)
	{
		--(*end);
		i = 0;
		while (set[i])
		{
			if (s1[*end] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
	}
}

static void	start_str(size_t *start, char const *set, const char *s1)
{
	size_t	i;

	i = 0;
	while (s1[*start])
	{
		i = 0;
		while (set[i])
		{
			if (s1[*start] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
		(*start)++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	end_str(&end, set, s1);
	start = 0;
	start_str(&start, set, s1);
	if (end >= start)
		return (copy_str(end, start, s1));
	str = malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}
