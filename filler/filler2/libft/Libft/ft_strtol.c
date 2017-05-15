/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:22:13 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/08 16:26:37 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strtol(const char *nptr)
{
	const char	*s = nptr;
	int			c;
	int			neg;
	long		ret;

	if (nptr == NULL)
		ft_put_error();
	neg = 1;
	while (ft_isspace(*s))
		c = *s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			neg = -1;
		c = *s++;
	}
	ret = 0;
	while (ft_isdigit(*s))
		ret = 10 * ret + *s++ - '0';
	return (ret * neg);
}
