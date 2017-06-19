/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stris.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:35:08 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/19 15:36:42 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stris(const char *s, int (*f)(int))
{
	size_t i;

	if (s == NULL || f == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (f(((char *)(uintptr_t)s)[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
