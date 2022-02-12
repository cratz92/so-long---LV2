/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:22:05 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/03/01 03:22:05 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_extra(long n, char next_digit, int sign)
{
	int	check;

	check = 0;
	if (n == INT_MAX / 10 && next_digit <= '7' && sign == 1)
		check = 0;
	else if (n == INT_MAX / 10 && next_digit <= '8' && sign == -1)
		check = 0;
	else if (n >= INT_MAX)
		check = 1;
	return (check);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	if (str[0] == '\0')
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_extra(nbr, str[i], sign))
			return (0);
		nbr = (nbr * 10) + (int)(str[i] - '0');
		i++;
	}
	return (sign * nbr);
}
