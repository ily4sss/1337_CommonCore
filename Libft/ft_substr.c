/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:48:56 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/29 16:16:21 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	alloc_size(size_t copy_mem, size_t start, size_t i, size_t len)
{
	size_t	nmem;

	nmem = 0;
	if (start < i)
		nmem = i - start;
	if (len < nmem)
		copy_mem = len;
	else
		copy_mem = nmem;
	return (copy_mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	copy_mem;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	copy_mem = alloc_size(0, start, i, len);
	str = malloc(copy_mem + 1);
	if (str == NULL)
		return (NULL);
	if (start >= i || len == 0)
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (i < copy_mem)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
