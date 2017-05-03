/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lpwr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:28:04 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/09 18:25:14 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lpwr(long long nb, int pwr)
{
	long n;

	n = nb;
	if (pwr < 0)
		return (0);
	if (pwr == 0)
		return (1);
	if (pwr)
	{
		n = ft_lpwr(nb, pwr - 1);
		nb = nb * n;
	}
	return (nb);
}
