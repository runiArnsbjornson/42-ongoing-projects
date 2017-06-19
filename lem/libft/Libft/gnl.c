/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:25:22 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/19 10:32:10 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_fix(char *buff, char *stock, char **line)
{
	if ((buff = ft_strchr(stock, '\0')) != NULL)
	{
		*buff = '\0';
		*line = ft_strdup(stock);
		*stock = '\0';
		return (1);
	}
	return (0);
}

static char		*get_buff(const int fd, char *stock, long *ret)
{
	char		*tmp;
	char		buff[BUFF_SIZE + 1];

	*ret = read(fd, buff, BUFF_SIZE);
	buff[*ret] = '\0';
	tmp = stock;
	stock = ft_strjoin(stock, buff);
	ft_strdel(&tmp);
	return (stock);
}

int				gnl(const int fd, char **line)
{
	char		*buff;
	long		ret;
	static char	*stock;

	buff = NULL;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	ret = 1;
	stock = stock ? stock : ft_strnew(0);
	while (ret > 0)
	{
		if ((stock = get_buff(fd, stock, &ret)) != NULL && ret == -1)
		{
			ft_strclr(stock);
			return (-1);
		}
		if ((buff = ft_strchr(stock, '\n')) != NULL)
		{
			*buff = '\0';
			*line = ft_strdup(stock);
			ft_memmove(stock, buff + 1, ft_strlen(buff + 1) + 1);
			return (1);
		}
	}
	return ((*stock == '\0') ? 0 : ft_fix(buff, stock, line));
}
