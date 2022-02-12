/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:02:43 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/04/15 02:01:26 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destSize)
{
	size_t	i;
	size_t	size;

	if (!src)
		return (0);
	size = 0;
	while (src[size])
		size++;
	if (destSize < 1)
		return (size);
	i = 0;
	while (src[i] && (i < (destSize - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size);
}
