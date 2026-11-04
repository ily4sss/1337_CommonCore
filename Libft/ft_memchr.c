/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:46:12 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/29 15:29:56 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;
	size_t				i;

	mem = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
			return ((void *)&mem[i]);
		i++;
	}
	return (NULL);
}
