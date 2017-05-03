/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 11:17:29 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/02 09:44:49 by jdebladi         ###   ########.fr       */
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
	data.graph = 0;
	init(&data, ref);
	parse(&data, ref);
	return (0);
}
