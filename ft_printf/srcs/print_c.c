/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:28:54 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/12 17:15:41 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_c(char c, int *len, t_flags fl)
{
	if (fl.minus == 0 && fl. width > 0)
	{
		while (fl.width > 1)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
		ft_putchar_len(c, len);
	}
	else if (fl.minus == 1)
	{
		ft_putchar_len(c, len);
		while (fl.width > 1)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
	}
	else
		ft_putchar_len(c, len);
}
