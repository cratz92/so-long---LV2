/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 04:09:48 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/03/15 04:09:48 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*ptr;
	unsigned char	letra;
	size_t			i;

	str = (unsigned char *)s;
	ptr = (unsigned char *)s;
	letra = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = letra;
		i++;
	}
	return ((void *)str);
}
