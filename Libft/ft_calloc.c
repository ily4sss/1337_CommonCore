/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:37:09 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/11/01 17:24:12 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	char			*mem;

	if (size && ((nmemb * size) / size) != nmemb)
		return (NULL);
	i = nmemb * size;
	if (i == 0)
		i = 1;
	mem = malloc(i);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, i);
	return (mem);
}
