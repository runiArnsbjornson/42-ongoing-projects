/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:35:54 by jdebladi          #+#    #+#             */
/*   Updated: 2016/12/08 14:07:25 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bool_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp[i])
	{
		if (tmp[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
