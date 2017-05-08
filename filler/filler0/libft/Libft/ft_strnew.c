/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:14:58 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/14 18:55:07 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*ret;

	if ((ret = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
