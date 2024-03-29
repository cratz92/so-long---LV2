/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:30:09 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/12 20:20:22 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_xx(t_flags fl, va_list args, int *len, const char c)
{
	int	size;

	fl.ulli = va_arg(args, unsigned int);
	if (c == 'X')
		fl.str_num = ft_ullitoa_base(fl.ulli, HEXAUPP);
	else if (c == 'x')
		fl.str_num = ft_ullitoa_base(fl.ulli, HEXALOW);
	size = (int)ft_strlen(fl.str_num);
	if (fl.ulli == 0 && fl.dot == 1 && fl.precision == 0)
		print_zero_corner_cases(fl, size, len);
	else if ((fl.width == 0 || fl.width <= size)
		&& (fl.precision == 0 || fl.precision <= size))
		basic_output_check_hash_xx(fl, len, c);
	else if ((fl.width == 0 || fl.width <= size) && (fl.precision > size))
		print_precision_zero_i_d(fl, size, len);
	else if (fl.width > size && (fl.precision == 0 || fl.precision <= size))
		print_regular_cases_xx(fl, size, len);
	else if (fl.width > size && fl.precision > size)
		print_corner_cases_xx(fl, size, len);
	free(fl.str_num);
}

int	ft_len_hex(unsigned long int x)
{
	int	len;

	len = 0;
	while (x)
	{
		x = x / 16;
		len++;
	}
	return (len);
}

char	*ft_ullitoa_base(unsigned long long int n, char *base)
{
	char						*result;
	unsigned long long int		number;
	size_t						size;
	int							base_len;

	base_len = ft_strlen(base);
	number = n;
	size = 1;
	n /= base_len;
	while (n)
	{
		size++;
		n /= base_len;
	}
	result = (char *)malloc(size + 1);
	if (!result)
		return (0);
	result[size--] = '\0';
	while (number > 0)
	{
		result[size--] = base[number % base_len];
		number /= base_len;
	}
	if (size == 0 && result[1] == '\0')
		result[0] = '0';
	return (result);
}

void	print_corner_cases_xx(t_flags fl, int size, int *len)
{
	int	i;

	i = 0;
	if (fl.minus == 1)
	{
		if (fl.width == fl.precision)
			print_precision_zero_i_d(fl, size, len);
		else if (fl.width > fl.precision)
		{
			print_precision_zero_i_d(fl, size, len);
			while (fl.width - (fl.precision + i) > 0)
			{
				write(1, " ", 1);
				fl.width--;
				(*len)++;
			}
		}
		else
			print_precision_zero_i_d(fl, size, len);
	}
	else
	{
		print_simple_space_width_precision_i_d(fl, len);
		print_precision_zero_i_d(fl, size, len);
	}
}

void	print_regular_cases_xx(t_flags fl, int size, int *len)
{	
	if (fl.minus == 1)
	{
		ft_putstr_len(fl.str_num, len);
		print_simple_space_width_i_d(fl, size, len);
	}
	else if (fl.zero == 0 || (fl.zero == 1 && fl.dot == 1))
	{
		print_simple_space_width_i_d(fl, size, len);
		ft_putstr_len(fl.str_num, len);
	}
	else
	{
		print_simple_zero_xx(fl, size, len);
		ft_putstr_len(fl.str_num, len);
	}
}
