/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:51:40 by jdebladi          #+#    #+#             */
/*   Updated: 2016/09/21 23:35:18 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_display(t_bsq *data)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i - 1 < data->nb_line)
	{
		j = 0;
		while (data->tab[i][j] != '\0')
		{
			if (i >= (data->coordi - (data->max - 1)) && i <= data->coordi &&
					j >= (data->coordj - (data->max - 1)) && j <= data->coordj)
				ft_putchar(data->sqr);
			else
				ft_putchar(data->tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
