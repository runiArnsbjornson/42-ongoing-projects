/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:25:57 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/24 16:34:19 by jdebladi         ###   ########.fr       */
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
			free(tab[i]);
		free(tab);
	}
}
