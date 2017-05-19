/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 10:14:19 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/17 14:11:24 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	ft_error(t_data *data, char *str)
{
	ft_putstr_fd(RED "Error" RES, 2);
	if (str)
	{
		ft_putstr_fd(RED " : " RES, 2);
		ft_putendl_fd(str, 2);
	}
	else
		ft_putstr_fd("\n", 2);
	free(data);
	exit(0);
}

void	init(t_data *data, int *ref)
{
	if (!data->piece)
	{
		if ((data->piece = malloc(sizeof(t_piece))) == 0)
			perror("Error malloc");
	}
	data->piece->x = -2;
	data->piece->y = -2;
	if (!data->board)
	{
		if ((data->board = malloc(sizeof(t_board))) == 0)
			perror("Error malloc");
	}
	data->board->x = -2;
	data->board->y = -2;
	data->graph = 1;
	ref[0] = 0;
	ref[1] = 0;
	ref[2] = 0;
	ref[3] += 1;
	ref[4] += 1;
}

int		main(void)
{
	t_data	*data;
	int		ref[6];
	int		i;

	i = 0;
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		perror("Error malloc");
	data->piece = NULL;
	data->board = NULL;
	while (i <= 5)
	{
		ref[i] = 0;
		++i;
	}
	init(data, ref);
	parse(data, ref);
	return (0);
}
