/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:15:18 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/02 10:12:56 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putinttab(int **tab, int col)
{
	int x;
	int y;
	int i;

	i = -1;
	ft_printf("\t");
	while (++i < col)
		ft_printf(MAG "%d%s", i, i == col - 1 ? "\n" RES : "\t");
	i = 0;
	y = -1;
	while (tab[++y] != NULL)
	{
		x = -1;
		ft_printf(MAG "%d\t" RES, i++);
		while (++x < col)
			ft_printf("%d%c", tab[y][x], x == col - 1 ? '\n' : '\t');
	}
}
