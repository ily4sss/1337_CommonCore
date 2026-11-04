/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:35:59 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/31 12:58:33 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	char	*str;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	length = 0;
	while (s[length])
	{
		str[length] = f((unsigned int)length, s[length]);
		length++;
	}
	str[length] = '\0';
	return (str);
}
