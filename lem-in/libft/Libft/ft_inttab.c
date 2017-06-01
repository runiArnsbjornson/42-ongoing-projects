/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:34:48 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/01 17:23:37 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_inttab(int col, int line)
{
	int	i;
	int	**tab;

	i = 0;
	if (!line || !(tab = (int **)ft_memalloc(sizeof(int *) * (unsigned long)(line + 1))) || !col)
		return (NULL);
	while (i < line)
	{
		if (!(tab[i] = ft_memalloc(sizeof(int) * (unsigned long)(col))))
		{
			ft_inttabdel(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
