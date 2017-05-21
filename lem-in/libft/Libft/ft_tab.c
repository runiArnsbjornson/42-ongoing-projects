/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:39:28 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 13:57:58 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab(size_t col, size_t line)
{
	size_t	i;
	char	**tab;

	i = 0;
	if (!line || !(tab = malloc(sizeof(char *) * (line + 1))) || !col)
		return (NULL);
	while (i < line)
	{
		tab[i] = malloc(sizeof(char) * (col + 1));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
