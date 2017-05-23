/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:43 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/23 17:00:00 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	pathfinding(t_data *data)
{
	// int turn;
	int **sol;
	t_pos pos;

	// turn = -1;
	sol = data->paths;
	pos.x = 0;
	while (pos.x < data->rooms)
	{
		pos.y = 0;
		while (pos.y < data->rooms)
		{
			ft_printf("%d ", sol[pos.x][pos.y]);
			pos.y++;
		}
		ft_printf("\n");
		pos.x++;
	}
}

