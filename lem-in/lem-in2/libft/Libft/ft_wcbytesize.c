/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcbytesize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:00:35 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/02 11:22:52 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcbytesize(wchar_t wc)
{
	char	*bin;
	int		len;
	int		nb_bytes;

	nb_bytes = 0;
	bin = ft_itoa_base(wc, 2);
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
	return (nb_bytes);
}
