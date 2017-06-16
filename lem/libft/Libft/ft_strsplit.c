/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:28:31 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 13:56:18 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_words(const char *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static size_t	ft_count_char(char *word, char c)
{
	size_t n;

	n = 0;
	while (*word != c && *word)
	{
		n++;
		word++;
	}
	return (n);
}

static char		*ft_letter(const char *s, size_t start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!(s) || len <= 0 || !(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	size_t	words;
	size_t	i;
	size_t	j;

	words = ft_count_words((char *)(uintptr_t)s, c);
	if (!(ret = malloc(sizeof(char *) * (words + 1))) || !s || !c)
		return (NULL);
	i = 0;
	j = 0;
	while (words > 0 && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		ret[j] = ft_letter(s, i, ft_count_char((char *)(uintptr_t)s + i, c));
		i += ft_count_char((char *)(uintptr_t)s + i, c);
		j++;
		words--;
	}
	ret[j] = NULL;
	return (ret);
}
