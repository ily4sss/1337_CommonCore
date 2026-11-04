/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ily4s <ily4s@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:40:32 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/19 14:21:20 by ily4s            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_impl(size_t *digits, long num, int sign)
{
	char	*str;

	str = malloc((*digits) + 1);
	if (str == NULL)
		return (NULL);
	str[*digits] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (num > 0 && *digits > 0)
	{
		str[--(*digits)] = (num % 10) + '0';
		num /= 10;
	}
	if (*digits == 1 && sign == -1)
		str[--(*digits)] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	long	num;
	long	divisor;
	size_t	digits;
	int		sign;

	num = n;
	sign = 1;
	divisor = 1;
	digits = 1;
	if (num < 0)
	{
		num = -num;
		sign = -1;
		digits++;
	}
	while ((num / divisor) >= 10)
	{
		divisor *= 10;
		digits++;
	}
	return (str_impl(&digits, num, sign));
}
