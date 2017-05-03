/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:52:32 by jdebladi          #+#    #+#             */
/*   Updated: 2016/12/08 17:16:12 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_compare(int i, int j, int k, int r)
{
	int tmp;

	tmp = i;
	if (r == 0)
		return (0);
	if (tmp >= j)
		tmp = j;
	if (tmp >= k)
		tmp = k;
	return (tmp + 1);
}

void	ft_find(t_bsq *data)
{
	int i;
	int j;
	int max;

	i = 1;
	max = data->max;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->tab[i][j] != '\0')
		{
			if (data->res[i][j] > data->max)
			{
				data->max = data->res[i][j];
				data->coordi = i + 1;
				data->coordj = j;
			}
			j++;
		}
		i++;
	}
}

t_bsq	*ft_resolve_2(t_bsq *data)
{
	int i;
	int j;

	i = 1;
	while (i < data->nb_line)
	{
		j = 0;
		while (j < ft_strlen(data->tab[1]))
		{
			data->res[i][j] = ft_compare(data->res[i - 1][j], data->res
					[i][j - 1], data->res[i - 1][j - 1], data->res[i][j]);
			j++;
		}
		i++;
	}
	ft_find(data);
	return (data);
}

t_bsq	*ft_resolve(t_bsq *data)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i - 1 < data->nb_line)
	{
		j = 0;
		while (data->tab[i][j])
		{
			if (data->tab[i][j] != data->emp)
				data->res[i - 1][j] = 0;
			else
				data->res[i - 1][j] = 1;
			j++;
		}
		i++;
	}
	ft_resolve_2(data);
	ft_display(data);
	return (data);
}
