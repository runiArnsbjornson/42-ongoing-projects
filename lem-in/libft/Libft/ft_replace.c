/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:52:44 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 13:32:23 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_skip(const char *s, const char *old, int len)
{
	if (!*old)
		return ((size_t)len);
	if (!*s)
		return (0);
	if (*s == *old)
		return (ft_skip(s + 1, old + 1, len + 1));
	return (1);
}

static size_t	ft_len(const char *s, const char *old, size_t len_new)
{
	size_t len_s;
	size_t len_old;
	size_t next;

	if (!*s)
		return (0);
	len_s = ft_strlen(s);
	if (!*old)
		return (len_s + len_new);
	len_old = ft_strlen(old);
	while (*s)
	{
		next = ft_skip(s, old, 1);
		if (next == 0)
			return (len_s);
		if (next > 1)
		{
			len_s = (len_s - len_old) + len_new;
			next--;
		}
		s += next;
	}
	return (len_s);
}

char			*ft_replace(const char *s, const char *old, const char *new)
{
	size_t	len_new;
	size_t	next;
	char	*ret;

	if (!old)
		return ((char *)(uintptr_t)s);
	len_new = ft_strlen(new);
	if (!(ret = malloc(sizeof(char) * ft_len(s, old, len_new) + 1)))
		return (NULL);
	ret[0] = '\0';
	while (*s)
	{
		next = ft_skip(s, old, 1);
		if (next == 0)
			return (ft_strcat(ret, s));
		if (next > 1)
		{
			ft_strcat(ret, new);
			next--;
		}
		else
			ft_strncat(ret, s, 1);
		s += next;
	}
	return (ret);
}
