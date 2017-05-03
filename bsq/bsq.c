/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:51:29 by jdebladi          #+#    #+#             */
/*   Updated: 2016/12/08 17:20:10 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq	*ft_init_struct(t_bsq *data)
{
	if ((data = malloc(sizeof(t_bsq))) == NULL)
		return (NULL);
	data->nb_line = 0;
	data->obs = 0;
	data->emp = 0;
	data->sqr = 0;
	data->max = 0;
	data->coordi = 0;
	data->coordj = 0;
	data->tab = NULL;
	data->res = NULL;
	return (data);
}

int		ft_puterror(int nb)
{
	if (nb == 1)
	{
		write(2, "map error\n", 10);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE + 1];
	t_bsq	*data = NULL;

	i = 0;
	data = ft_init_struct(data);
	while (av[++i] && i < ac)
	{
		if ((fd = open(av[i], O_RDONLY | O_DIRECTORY)) >= 0)
			return (ft_puterror(1));
		else
		{
			if ((fd = open(av[i], O_RDONLY)) <= 0)
				return (ft_puterror(1));
			while ((ret = read(fd, buff, BUFF_SIZE)))
			{
				buff[ret] = '\0';
				printf("test1\n");
				check_map(buff, data);
			}
			printf("test2\n");
		}
		ft_resolve(data);
	}
	return (0);
}
