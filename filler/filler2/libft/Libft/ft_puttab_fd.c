/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:03:59 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/16 18:04:28 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_fd(char **tab, int fd)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd((char *)tab[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
