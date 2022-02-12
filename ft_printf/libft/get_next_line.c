/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:15:48 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/10 07:43:53 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	extra_save(char **line, char **save, int pos)
{
	char	*new_save;

	ft_strcpy_gnl(*line, *save, '\n');
	if (!(*save)[pos + 1])
	{
		free(*save);
		*save = NULL;
		return ;
	}
	new_save = ft_update_save(&(*save)[pos + 1]);
	free(*save);
	*save = new_save;
	if (!(*save))
	{
		free(*line);
		*line = NULL;
	}
}

int	ft_check_save(char **line, char **save)
{
	int	i;

	i = 0;
	if (!(*save))
		return (LINE_NOT_FULL);
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	if ((*save)[i] == '\n')
	{
		*line = malloc(sizeof(char) * (i + 2));
		extra_save(line, save, i);
		return (RETURN_LINE);
	}
	*line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (RETURN_LINE);
	ft_strcpy_gnl(*line, *save, '\0');
	free(*save);
	*save = NULL;
	return (LINE_NOT_FULL);
}

static void	extra_buf(char **line, char *buf, char **save, int pos)
{
	int	i;

	i = pos + 1;
	if (!buf[i])
		return ;
	while (buf[i])
		i++;
	*save = malloc(sizeof(char) * (i + 1));
	if (!(*save))
	{
		free(*line);
		*line = NULL;
		return ;
	}
	ft_strcpy_gnl(*save, &buf[pos + 1], '\0');
}

int	ft_check_buf(char **line, char *buf, char **save)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (ft_concat(line, buf, buf[i]) == RETURN_LINE)
		return (RETURN_LINE);
	if (buf[i] == '\n')
	{
		extra_buf(line, buf, save, i);
		return (RETURN_LINE);
	}
	return (LINE_NOT_FULL);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	line = NULL;
	if (ft_check_save(&line, &save) == RETURN_LINE)
		return (line);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == ERROR)
		return (NULL);
	buf[ret] = '\0';
	while (ret)
	{
		ret = ft_check_buf(&line, buf, &save);
		if (ret == RETURN_LINE)
			return (line);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == ERROR)
			return (NULL);
		buf[ret] = '\0';
	}
	return (line);
}
