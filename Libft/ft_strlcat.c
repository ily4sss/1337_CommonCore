/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:48:11 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/29 15:46:58 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;
	size_t	orig_dest_size;

	dst_size = 0;
	src_size = 0;
	while (dst_size < dstsize && dst[dst_size])
		dst_size++;
	while (src[src_size])
		src_size++;
	i = 0;
	if (dstsize == 0 || dst_size == dstsize)
		return (dst_size + src_size);
	orig_dest_size = dst_size;
	while (src[i] && i < (dstsize - orig_dest_size - 1))
	{
		dst[dst_size] = src[i];
		dst_size++;
		i++;
	}
	dst[dst_size] = '\0';
	return (orig_dest_size + src_size);
}
