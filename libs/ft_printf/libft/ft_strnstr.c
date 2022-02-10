/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 08:12:53 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/04/18 13:06:34 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < n)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && big[i + j] && i + j < n
				&& big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
