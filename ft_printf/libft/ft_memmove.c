/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 02:21:59 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/03/15 02:21:59 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*destptr;
	void	*srcptr;

	destptr = dest;
	srcptr = (void *)src;
	if (destptr > srcptr && src + n > dest)
	{
		srcptr += n;
		destptr += n;
		while (n--)
			*(char *)--destptr = *(char *)--srcptr;
	}
	else if (dest < src && dest + n >= src)
	{
		while (n--)
			*(char *)destptr++ = *(char *)srcptr++;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
