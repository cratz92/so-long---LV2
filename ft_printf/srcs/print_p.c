/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:29:14 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/12 19:48:10 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_p(t_flags fl, va_list args, int *len, const char c)
{
	int	size;

	fl.str_num = ft_int_to_hex_p(va_arg(args, unsigned long int), c);
	size = (int)ft_strlen(fl.str_num);
	size = size + 2;
	if (fl.zero == 0 && fl.width > size)
		print_no_zero_p(fl, len, size);
	else if (fl.zero == 1 && fl.width > size)
		print_zero_p(fl, len, size);
	else
		ft_putstr_len_p(fl.str_num, len);
	free(fl.str_num);
}

void	print_no_zero_p(t_flags fl, int *len, int size)
{
	if (fl.minus == 0)
	{
		print_space(fl, size, len);
		ft_putstr_len_p(fl.str_num, len);
	}
	else if (fl.minus == 1)
	{
		ft_putstr_len_p(fl.str_num, len);
		print_space(fl, size, len);
	}
}

void	print_zero_p(t_flags fl, int *len, int size)
{
	if (fl.minus == 0)
	{
		ft_putstr_len("0x", len);
		while (fl.width - size > 0)
		{
			write(1, "0", 1);
			fl.width--;
			(*len)++;
		}
		ft_putstr_len(fl.str_num, len);
	}
	else if (fl.minus == 1)
	{
		ft_putstr_len_p(fl.str_num, len);
		print_space(fl, size, len);
	}
}

void	ft_putstr_len_p(char *s, int *len)
{
	int	i;

	ft_putstr_len("0x", len);
	if (s != NULL)
	{
		i = 0;
		while (s[i])
			ft_putchar_len(s[i++], len);
	}
}

char	*ft_int_to_hex_p(unsigned long int n, const char c)
{
	int						len;
	char					*result;
	unsigned long int		temp;

	len = ft_len_hex(n);
	if (n == 0)
		len++;
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (0);
	result[len--] = '\0';
	while (len >= 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
			result[len--] = temp + 48;
		else if (c == 'p')
			result[len--] = temp + 87;
		n = n / 16;
	}
	return (result);
}
