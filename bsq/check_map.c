/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:51:14 by jdebladi          #+#    #+#             */
/*   Updated: 2016/12/08 17:41:55 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq	*ft_parse(char *str, t_bsq *data)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if ((data->tab = ft_split(str)) == NULL)
		return (NULL);
	printf("test4\n");
	while (data->tab[0][j])
		j++;
	data->emp = data->tab[0][j - 3];
	data->obs = data->tab[0][j - 2];
	data->sqr = data->tab[0][j - 1];
	data->nb_line = ft_atoi(ft_strcut(data->tab[0], 0, j - 3));
	if ((data->res = (int **)malloc(sizeof(int*) * data->nb_line)) == NULL)
		return (NULL);
	while (i <= data->nb_line)
	{
		data->res[i] = (int *)malloc(sizeof(int) * ft_strlen(data->tab[1]));
		i++;
	}
	printf("test5\n");
	return (data);
}

int		check_map(char *str, t_bsq *data)
{
	int i;
	int j;

	if (!ft_parse(str, data))
		return (0);
	printf("test3\n");
	i = 1;
	j = 0;
	if (data->nb_line != (ft_str_nb_line(str) - 1))
		return (0);
	while (data->tab[i][j])
	{
		if (ft_strlen(data->tab[i]) != ft_strlen(data->tab[1]))
			return (0);
		while (data->tab[i][j])
		{
			if (data->tab[i][j] == data->emp || data->tab[i][j] == data->obs)
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
