/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:25:57 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/01 13:34:53 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_inttabdel(int **tab, int size)
{
	int i;

	if (tab != NULL)
	{
		i = -1;
		while (++i < size)
		{
			if (tab[i] != NULL)
				free(tab[i]);
		}
		free(tab);
	}
}
