/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:34:35 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/10 10:44:15 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nfree(int nbr, ...)
{
	int		i;
	va_list	args;
	void	*array;

	i = 0;
	va_start(args, nbr);
	while (i < nbr)
	{
		if(!array = va_arg(args, void *))
		{
			ft_putendl_fd("Error: nbr too big", 2);
			exit (0);
		}
		free(array);
		i++;
	}
	va_end(args);
}