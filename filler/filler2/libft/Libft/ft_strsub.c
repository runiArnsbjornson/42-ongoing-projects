/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:25:44 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/16 11:00:44 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if ((ret = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (ret);
}
