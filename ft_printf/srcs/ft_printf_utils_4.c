/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:27:31 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/12 19:41:19 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_precision_neg_zero_number_i_d(t_flags fl, int size, int *len)
{
	ft_putchar_len('-', len);
	while (fl.precision - (size - 1) > 0)
	{
		write(1, "0", 1);
		fl.precision--;
		(*len)++;
	}
	ft_putstr_len(fl.str_num, len);
}

void	print_width_neg_zero_number_i_d(t_flags fl, int size, int *len)
{
	ft_putchar_len('-', len);
	while (fl.width - (size - 1) > 0)
	{
		write(1, "0", 1);
		fl.width--;
		(*len)++;
	}
	ft_putstr_len(fl.str_num, len);
}

void	print_neg_precision_zero_number_i_d(t_flags fl, int size, int *len)
{
	ft_putchar_len('-', len);
	while (fl.precision > size - 1)
	{
		write(1, "0", 1);
		fl.precision--;
		(*len)++;
	}
	ft_putstr_len(fl.str_num, len);
}

void	print_neg_prec_zero_number_space_i_d(t_flags fl, int size, int *len)
{
	print_neg_precision_zero_number_i_d(fl, size, len);
	while (fl.width - (size - 1) > 0)
	{
		write(1, " ", 1);
		fl.width--;
		(*len)++;
	}
}

void	print_neg_number_space_i_d(t_flags fl, int size, int *len)
{
	print_neg_number_i_d(fl, len);
	print_space(fl, size, len);
}
