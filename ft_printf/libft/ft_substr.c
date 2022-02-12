/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 06:34:02 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/03/15 06:34:02 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size <= start)
		size = 0;
	if (size > len)
		size = len;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	if (size != 0)
	{
		while (len-- && s[start + i] != 0)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
