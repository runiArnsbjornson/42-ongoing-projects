/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:54:48 by jdebladi          #+#    #+#             */
/*   Updated: 2016/09/21 19:54:53 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (src[i])
		i++;
	if ((str = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	j = 0;
	while (src[j])
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
