/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:46:49 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/29 16:22:53 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*str_dest;
	const unsigned char	*str_src;
	size_t				i;

	str_dest = (unsigned char *)dest;
	str_src = (const unsigned char *)src;
	i = 0;
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			str_dest[i] = str_src[i];
		}
	}
	else if (src > dest)
		ft_memcpy(str_dest, str_src, n);
	return (dest);
}
