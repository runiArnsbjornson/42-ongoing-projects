/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:54:33 by jdebladi          #+#    #+#             */
/*   Updated: 2016/09/21 19:54:41 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcut(const char *str, int begin, int len)
{
	char	*s1;
	int		i;
	int		j;

	if (str == NULL || len <= 0)
		return (NULL);
	if ((s1 = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = begin;
	j = 0;
	while (j < len)
	{
		s1[j] = str[i];
		j++;
		i++;
	}
	s1[j] = '\0';
	return (s1);
}
