/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:00:00 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/11/15 18:26:31 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	concatenation(char const *s, size_t *i, size_t S, char *str)
{
	while (s[S])
	{
		str[*i] = s[S];
		(*i)++;
		S++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	size_t	i;

	if (!s1)
		s1 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (str == NULL)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	i = 0;
	concatenation(s1, &i, s1_len, str);
	concatenation(s2, &i, s2_len, str);
	str[i] = '\0';
	return (str);
}

char	*cut_str(char *str, int i)
{
	int		j;
	char	*s;

	j = 0;
	if (!str)
		return (NULL);
	s = malloc(i + 2);
	if (!s)
		return (NULL);
	while (j <= i && str[j])
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

int	clean_exit(char **stash, char *buffer)
{
	free(buffer);
	free(*stash);
	*stash = NULL;
	return (0);
}
