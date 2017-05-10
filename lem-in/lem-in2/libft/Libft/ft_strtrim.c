/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:27:46 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/12 16:34:13 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ret;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while (j != 0 && (s[--j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i <= j)
		i++;
	if ((ret = (char *)malloc(sizeof(const char) * (j - i + 2))) == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
		ret[k++] = s[i++];
	ret[k] = '\0';
	return (ret);
}
