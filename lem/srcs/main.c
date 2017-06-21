/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:45:24 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/21 14:00:20 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	ft_free(t_data *d)
{
	if (d->r != NULL)
		ft_lstfree(&d->r);
	if (d->p != NULL)
		ft_inttabdel(d->p, d->rooms);
	if (d->s != NULL)
		ft_inttabdel(d->s, d->lmax + d->rooms);
	if (d->t != NULL)
		ft_inttabdel(d->t, d->rooms);
	if (d->mark != NULL)
		free(d->mark);
	if (d->max != NULL)
		free(d->max);
	d = NULL;
}

void	graph_opt(char *av, t_data *d)
{
	int i;

	if (av[0] == '-')
	{
		i = 1;
		while (av[i])
		{
			if (check_opt(av[i]) == 0)
				bad_arg();
			d->graph = av[i] == 'd' ? d->graph | DATA : d->graph;
			d->graph = av[i] == 'r' ? d->graph | ROOM : d->graph;
			d->graph = av[i] == 'p' ? d->graph | PATH : d->graph;
			d->graph = av[i] == 's' ? d->graph | SOLV : d->graph;
			d->graph = av[i] == 'b' ? d->graph | BEST : d->graph;
			d->graph = av[i] == 'a' ? d->graph | ALL : d->graph;
			i++;
		}
	}
	else
		bad_arg();
}

void	init_data(t_data *d)
{
	d->r = NULL;
	d->p = NULL;
	d->s = NULL;
	d->t = NULL;
	d->best = NULL;
	d->mark = NULL;
	d->max = NULL;
	d->graph = 0;
	d->start = -1;
	d->end = -1;
	d->ants = 0;
	d->rooms = 0;
	d->lmax = 0;
	d->len = 0;
	d->pad = 0;
	d->x = 0;
	d->y = 0;
}

void	bad_arg(void)
{
	ft_putendl_fd("usage: ./lem-in [-drpsba] \033[04mfile\033[0m", 2);
	ft_putendl_fd("-d\tDisplay the data parsed", 2);
	ft_putendl_fd("-r\tDisplay the list of rooms", 2);
	ft_putendl_fd("-p\tDisplay the matrix of paths", 2);
	ft_putendl_fd("-s\tDisplay the matrix of solutions", 2);
	ft_putendl_fd("-b\tDisplay the best solution", 2);
	ft_putendl_fd("-a\tAll of the options above", 2);
	exit(0);
}

int		main(int ac, char **av)
{
	t_data	d;
	int		i;

	i = 0;
	if (ac == 1)
		bad_arg();
	init_data(&d);
	if (ac > 2)
	{
		while (++i < ac - 1)
			graph_opt(av[i], &d);
	}
	parser(&d, av[ac - 1]);
	check_data(&d);
	pathfinding(&d);
	shortening_best(&d);
	if (d.graph)
		display(&d, d.graph);
	display_solution(&d);
	ft_free(&d);
	return (0);
}
