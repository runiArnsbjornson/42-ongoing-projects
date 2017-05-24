/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:34:48 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/24 15:35:47 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_inttab(size_t col, size_t line)
{
	size_t	i;
	int	**tab;

	i = 0;
	if (!line || !(tab = ft_memalloc(sizeof(int *) * (line + 1))) || !col)
		return (NULL);
	while (i < line)
	{
		tab[i] = ft_memalloc(sizeof(int) * (col + 1));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
