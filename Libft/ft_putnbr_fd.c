/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ily4s <ily4s@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:47:39 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/19 14:39:07 by ily4s            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	long	divsior;
	char	buffer[32];
	size_t	i;

	num = n;
	divsior = 1;
	i = 0;
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	while ((num / divsior) >= 10)
		divsior *= 10;
	if (num == 0)
		write(fd, "0", 1);
	while (num > 0)
	{
		buffer[i] = (num % 10) + '0';
		i++;
		num /= 10;
	}
	while (i > 0)
		write(fd, &buffer[--i], 1);
}
