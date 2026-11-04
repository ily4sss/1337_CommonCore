/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:48:07 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/29 16:16:44 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	concatenation(char const *s, size_t *i, size_t S, char *str)
{
	while (s[S])
	{
		str[*i] = s[S];
		(*i)++;
		S++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
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
