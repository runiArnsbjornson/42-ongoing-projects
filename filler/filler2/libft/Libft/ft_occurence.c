/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occurence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:32:11 by jdebladi          #+#    #+#             */
/*   Updated: 2016/12/08 13:42:04 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_occurence(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	ret[127];

	j = 0;
	k = 0;
	ft_bzero(ret, 127);
	while (++k < ac)
	{
		i = 0;
		while (av[k][i])
		{
			if ((ft_bool_strchr(ret, av[k][i])) == 0)
			{
				ret[j] = av[k][i];
				j++;
			}
			i++;
		}
		ret[j] = '\0';
	}
	write(1, ret, ft_strlen(ret));
	write(1, "\n", 1);
}
