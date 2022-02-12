/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:21:42 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/04/13 04:21:42 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_extra(int n)
{
	int	nbr;

	nbr = 0;
	if (n < 0)
		n *= -1;
	nbr = n + 48;
	return (nbr);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		nbr;
	char	number;

	nbr = 0;
	if (0 <= n && n < 10)
	{
		number = ft_extra(n);
		write(fd, &number, 1);
		return ;
	}
	else if (-10 < n && n < 0)
	{
		number = ft_extra(n);
		write(fd, "-", 1);
		write(fd, &number, 1);
		return ;
	}
	nbr = n % 10;
	ft_putnbr_fd(n / 10, fd);
	number = ft_extra(nbr);
	write(fd, &number, 1);
}
