/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:09:26 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/21 09:50:00 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int ret;

	i = 0;
	n = 1;
	ret = 0;
	if (!str)
		ft_put_error("ft_atoi read NULL");
	if (ft_strlen(str) > 10)
		return ((int)ft_strtol(str));
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ret = (ret * 10 + (str[i]) - '0');
		i++;
	}
	return (ret * n);
}
