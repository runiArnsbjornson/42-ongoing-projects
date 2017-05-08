/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:19:34 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/09 14:15:34 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ret;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((ret = malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = f(((char *)s)[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
