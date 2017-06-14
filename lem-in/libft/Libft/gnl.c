/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:25:22 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/14 17:30:36 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_fix(char *buffer, char *stock, char **line)
{
	if ((buffer = ft_strchr(stock, '\0')) != NULL)
	{
		*buffer = '\0';
		*line = ft_strdup(stock);
		*stock = '\0';
		return (1);
	}
	return (0);
}

static char		*get_buff(const int fd, char *stock, long *ret_val)
{
	char		*temp;
	char		buffer[BUFF_SIZE + 1];

	*ret_val = read(fd, buffer, BUFF_SIZE);
	buffer[*ret_val] = '\0';
	temp = stock;
	stock = ft_strjoin(stock, buffer);
	ft_strdel(&temp);
	return (stock);
}

int				gnl(const int fd, char **line)
{
	char		*buffer;
	long		ret_val;
	static char	*stock;

	buffer = NULL;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	ret_val = 1;
	stock = stock ? stock : ft_strnew(0);
	while (ret_val > 0)
	{
		stock = get_buff(fd, stock, &ret_val);
		if (ret_val == -1)
		{
			ft_strclr(stock);
			return (-1);
		}
		if ((buffer = ft_strchr(stock, '\n')) != NULL)
		{
			*buffer = '\0';
			*line = ft_strdup(stock);
			ft_memmove(stock, buffer + 1, ft_strlen(buffer + 1) + 1);
			return (1);
		}
	}
	return ((*stock == '\0') ? 0 : ft_fix(buffer, stock, line));
}
