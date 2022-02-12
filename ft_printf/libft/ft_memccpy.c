/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 04:13:18 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/03/15 04:13:18 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = -1;
	while (++i < n && *s != (unsigned char)c)
	{
		*d = *s;
		d++;
		s++;
	}
	if (i == n)
		return (NULL);
	else
	{
		*d = *s;
		d++;
		return (d);
	}
}
