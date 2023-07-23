/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:49:45 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/25 14:54:43 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	abs_nb(long nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

static void	fn(long n, int fd)
{
	char	c;

	c = '-';
	if (n < 0)
	{
		write(fd, &c, 1);
		fn(abs_nb(n), fd);
	}
	if (n >= 10)
	{
		fn(n / 10, fd);
		fn((n % 10), fd);
	}
	else if (n <= 9 && n >= 0)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	fn(nb, fd);
}
