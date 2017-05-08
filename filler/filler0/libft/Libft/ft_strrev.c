/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:25:32 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/16 18:01:14 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char *start;
	char *t;
	char temp;

	start = s;
	t = ft_strchr(s, '\0');
	--t;
	while (s < t)
	{
		temp = *s;
		*s = *t;
		*t = temp;
		++s;
		--t;
	}
	return (start);
}
