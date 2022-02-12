/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 03:09:27 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/12/17 19:39:53 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destsize < 1)
		return (srclen + destsize);
	else if (destsize < destlen)
		return (srclen + destsize);
	else
	{
		while ((src[i] != '\0') && (destlen + i < destsize - 1))
		{
			dest[destlen + i] = src[i];
			i++;
		}
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
