/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsbytelen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:50:44 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 14:00:06 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcsbytelen(wchar_t *wc)
{
	int		nb_bytes;
	int		i;
	char	*bin;
	size_t	len;

	nb_bytes = 0;
	i = 0;
	while (wc[i])
	{
		bin = ft_itoa_base(wc[i], 2);
		len = ft_strlen(bin);
		free(bin);
		if (len <= 7)
			nb_bytes += 1;
		else if (len > 7 && len <= 11)
			nb_bytes += 2;
		else if (len > 11 && len <= 16)
			nb_bytes += 3;
		else
			nb_bytes += 4;
		++i;
	}
	return (nb_bytes);
}
