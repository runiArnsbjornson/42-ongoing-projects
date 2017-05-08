/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:29:59 by jdebladi          #+#    #+#             */
/*   Updated: 2016/12/19 12:37:37 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenght(char *str)
{
	size_t i;

	i = 0;
	while (str[i] && ft_isspace(str[i]) == 0)
		i++;
	return (i);
}

static int	nb_word(char *str)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			count++;
		while (!ft_isspace(str[i]) && str[i])
			i++;
		while (ft_isspace(str[i]) == 1)
			i++;
	}
	return (count);
}

char		**ft_split(char *str)
{
	char	**ret;
	int		i;
	int		j;
	int		k;
	int		len;

	if (!(ret = malloc(sizeof(char *) * nb_word(str) + 1)) || !str)
		return (NULL);
	i = 0;
	k = 0;
	while (str[k] && i <= nb_word(str))
	{
		j = 0;
		while (ft_isspace(str[k]) == 1)
			k++;
		len = lenght(&str[k]);
		if (!(ret[i] = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (j <= len)
			ret[i][j++] = str[k++];
		ret[i][len] = '\0';
		i++;
	}
	ret[nb_word(str)] = NULL;
	return (ret);
}
