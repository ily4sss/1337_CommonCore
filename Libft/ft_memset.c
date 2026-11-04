/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:46:53 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/25 12:51:29 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str_mem;
	size_t			i;

	str_mem = (unsigned char *)s;
	i = 0;
	while (i < n)
		str_mem[i++] = c;
	return (s);
}
