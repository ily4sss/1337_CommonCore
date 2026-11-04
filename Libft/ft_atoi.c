/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:30:10 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/31 13:56:04 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	uf_sign(long num, long max, int c)
{
	if ((num > (max - c) / 10))
		return (1);
	return (0);
}

static int	sign_return(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	size_t	i;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (uf_sign(num, 9223372036854775807, (str[i] - '0')))
			return (sign_return(sign));
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
