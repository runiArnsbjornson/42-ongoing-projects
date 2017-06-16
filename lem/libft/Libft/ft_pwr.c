/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:23:50 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/23 10:01:53 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_pwr(int nb, int power)
{
	unsigned long	n;

	if (power < 0)
		return (0);
	n = (unsigned long)nb;
	if (power == 0)
		return (1);
	if (power > 0)
	{
		n = ft_pwr(nb, power - 1);
		n = (unsigned long)nb * n;
	}
	return (n);
}
