/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:25:44 by exam              #+#    #+#             */
/*   Updated: 2016/12/08 17:46:11 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int n_word(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]) == 0)
			i++;
		while (s[i] && is_space(s[i]) == 1)
			i++;
		count++;
	}
	if (is_space(s[0]) == 1)
		count--;
	return (count);
}

int ft_slen(char *s)
{
	int i;

	i = 0;
	while (s[i] && is_space(s[i]) == 0)
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	int letter;
	int word;
	char **ret;

	i = 0;
	j = 0;
	word = n_word(str);
	ret = malloc(sizeof(char *) * word + 1);
	while (str[i] && word > 0)
	{
		if (is_space(str[i]) == 1)
			i++;
		else
		{
			letter = ft_slen(&str[i]);
			k = 0;
			ret[j] = malloc(sizeof(char) * letter + 1);
			while (str [i] && letter != 0)
			{
					ret[j][k] = str[i];
					k++;
					i++;
					letter--;
			}
			word--;
			ret[j][k] = '\0';
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}
