/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 09:27:57 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/02 17:19:38 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		main(void)
{
	t_data	data;
	int		ref[6];
	int		i;

	i = 0;
	while (i <= 5)
	{
		ref[i] = 0;
		++i;
	}
	data.graph = 1;
	init(&data, ref);
	parse(&data, ref);
	return (0);
}
