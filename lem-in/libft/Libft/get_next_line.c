/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:08:27 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/30 11:09:36 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenght(char *line, int start)
{
	int i;

	i = 0;
	while (line[start] != '\n')
	{
		start++;
		i++;
	}
	return (i);
}

static int	ft_save(char **line, char **rest, char *buf)
{
	char *tmp;
	char *tmp2;
	char *start;

	start = ft_strchr(buf, '\n');
	if (start)
	{
		tmp = ft_strsub(buf, 0, (size_t)ft_lenght(buf, 0));
		tmp2 = ft_strjoin(*line, tmp);
		ft_strdel(line);
		*line = tmp2;
		*rest = ft_strdup(start + 1);
		ft_strdel(&tmp);
		return (1);
	}
	else
	{
		tmp2 = ft_strjoin(*line, buf);
		ft_strdel(line);
		*line = tmp2;
		if (*rest)
			ft_bzero(*rest, 1);
		return (0);
	}
}

static int	ft_line(char **line, char **rest, char *buf, int fd)
{
	ssize_t ret;

	if (!ft_strcmp(buf, ""))
	{
		if (ft_save(line, rest, *rest) == 1)
			return (1);
	}
	else
	{
		if (ft_save(line, rest, buf) == 1)
			return (1);
	}
	ft_bzero(buf, BUFF_SIZE + 1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == 0 && ft_strcmp(*line, ""))
		return (1);
	else if (ret == 0)
		return (0);
	return (ft_line(line, rest, buf, fd));
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*rest = NULL;

	if (BUFF_SIZE == 0)
		return (0);
	if (read(fd, NULL, 0) == -1 || fd < 0 || line == NULL)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (rest == NULL || !ft_strcmp(rest, ""))
	{
		if (read(fd, buf, BUFF_SIZE) == 0)
			return (0);
	}
	*line = ft_strnew(1);
	return (ft_line(line, &rest, buf, fd));
}
