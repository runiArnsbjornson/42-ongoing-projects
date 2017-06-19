/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:47:40 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/19 11:11:45 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <time.h>

char	*get_content(t_list *t, int index)
{
	if (index > ft_lstlen(&t))
		return (NULL);
	while (t && index--)
		t = t->next;
	return (t->content);
}

void	display_rooms(t_data *d, t_list *tmp, int i)
{
	ft_printf(GRN "List of rooms :\n" RES);
	while (tmp)
	{
		ft_printf("%d : %s", i, tmp->content);
		if (i == d->start - 1)
			ft_printf(" << entrance\n");
		else if (i == d->end - 1)
			ft_printf(" << exit\n");
		else
			ft_printf("\n");
		tmp = tmp->next;
		i++;
	}
}

void	display_data(t_data *d, t_list *tmp, int i)
{
	ft_printf(BLU "Data parsed\n" RES);
	ft_printf("There are %d rooms and %d paths\n", d->rooms, (d->lmax - 1) / 2);
	while (tmp && i < d->start - 1)
	{
		tmp = tmp->next;
		i++;
	}
	ft_printf("%d ant%s in the anthill\n", d->ants, d->ants == 1 ? " is" : "s are");
	ft_printf("starting room is : %s\n", tmp->content);
	tmp = d->r;
	i = -1;
	while (tmp && ++i < d->end - 1)
		tmp = tmp->next;
	ft_printf("exit is in room : %s\n", tmp->content);
}

void	display_best(t_data *d, t_list *tmp, int i)
{
	if (d->best == NULL || (d->best[0] == d->best[1]))
		ft_error(d, "No solution found");
	while (++i < d->len + 1)
	{
		i == 0 ? ft_printf(BOL "Best solution :\n" RES) : 0;
		i == 0 ? ft_printf("shortest way is %d long\n", d->len + 1) : 0;
		ft_printf("%s%s", get_content(d->r, d->best[i]), i == d->len ? "\n" : " -> ");
		tmp = d->r;
	}
}

void	display(t_data *d, int type)
{
	t_list	*tmp;

	tmp = d->r;
	if (!!(type & (DATA << 0)) || (!!(type & (ALL << 0))))
		display_data(d, tmp, 0);
	if (!!(type & (ROOM << 0)) || (!!(type & (ALL << 0))))
		display_rooms(d, tmp, 0);
	if (!!(type & (PATH << 0)) || (!!(type & (ALL << 0))))
	{
		ft_printf(MAG "Matrix of paths :\n" RES);
		ft_putinttab(d->t, d->rooms);
	}
	if (!!(type & (SOLV << 0)) || (!!(type & (ALL << 0))))
	{
		ft_printf(YEL "Matrix of solution(s) :\n" RES);
		ft_putinttab(d->s, d->lmax);
	}
	if (!!(type & (BEST << 0)) || (!!(type & (ALL << 0))))
		display_best(d, tmp, -1);
}

void	ft_free(t_data *d)
{
	if (d->r != NULL)
		ft_lstfree(&d->r);
	if (d->p != NULL)
		ft_inttabdel(d->p, d->rooms);
	if (d->t != NULL)
		ft_inttabdel(d->t, d->rooms);
	if (d->mark != NULL)
		free(d->mark);
	if (d->s != NULL)
		ft_inttabdel(d->s, d->lmax + d->rooms);
	d = NULL;
}

void	ft_error(t_data *d, char *str)
{
	ft_put_error(str);
	ft_free(d);
	exit(0);
}

void	get_ants_nbr(t_data *d, int fd)
{
	char	*line;

	if (gnl(fd, &line) > 0)
	{
		if (!*line)
			ft_error(d, "Bad ants input");
		d->ants = ft_atoi(line);
		ft_strdel(&line);
	}
}

void	check_path(t_data *d, t_list *tmp, char *r1, char *r2)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (tmp)
	{
		if (ft_strcmp(r1, (char *)tmp->content) == 0)
		{
			d->y = i;
			check++;
		}
		if (ft_strcmp(r2, (char *)tmp->content) == 0)
		{
			d->x = i;
			check++;
		}
		tmp = tmp->next;
		i++;
	}
	if (check != 2 || d->x == d->y)
		ft_error(d, "Error with path");
}

void	get_path(t_data *d, char *line)
{
	char		*r1;
	t_list		*tmp;

	r1 = ft_strccpy(line, '-');
	if (d->p == NULL)
		if (!(d->p = ft_inttab(d->rooms, d->rooms)) ||
		!(d->t = ft_inttab(d->rooms, d->rooms)))
			ft_error(d, "Error malloc");
	tmp = d->r;
	check_path(d, tmp, r1, ft_strchr(line, '-') + 1);
	d->t[d->y][d->x] = 1;
	d->t[d->x][d->y] = 1;
	d->p[d->y][d->x] = 1;
	d->p[d->x][d->y] = 1;
	d->lmax++;
	ft_strdel(&r1);
}

void	check_rooms(t_data *d, char *r)
{
	t_list *tmp;

	if (ft_bool_strchr(r, '-'))
		ft_error(d, "Wrong room name");
	tmp = d->r;
	while (tmp)
	{
		if (ft_strcmp(r, tmp->content) == 0)
			ft_error(d, "Duplicate room name");
		tmp = tmp->next;
	}
}

void	get_room(t_data *d, char *line)
{
	char	*r;
	t_list	*tmp;

	if (*line == 'L' || *line == '#')
		ft_error(d, "Wrong room name");
	r = ft_strccpy(line, 32);
	check_rooms(d, r);
	if ((tmp = ft_lstnew(r, ft_strlen(r))) == NULL)
		ft_error(d, "Error malloc");
	ft_lstaddend(&d->r, tmp);
	d->rooms++;
	if (d->start == 0)
		d->start = d->rooms;
	if (d->end == 0)
		d->end = d->rooms;
	ft_strdel(&r);
}

void	get_type(t_data *d, char *line, int fd)
{
	if (ft_strcmp(line, "##start") == 0 && d->start == -1)
	{
		d->start = 0;
		if (gnl(fd, &line) > 0)
		{
			get_room(d, line);
			ft_strdel(&line);
		}
	}
	else if (ft_strcmp(line, "##end") == 0 && d->end == -1)
	{
		d->end = 0;
		if (gnl(fd, &line) > 0)
		{
			get_room(d, line);
			ft_strdel(&line);
		}
	}
	else if (ft_strcmp(line, "##end") == 0 || ft_strcmp(line, "##start") == 0)
		ft_error(d, "Redefinition of start/end");
}

void	parser(t_data *d, char *av)
{
	char	*line;
	int		fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error(d, "Read failed");
	get_ants_nbr(d, fd);
	while (gnl(fd, &line) > 0)
	{
		if (!*line)
			break ;
		if (ft_strncmp(line, "##", 2) == 0)
			get_type(d, line, fd);
		else if (*line == '#')
			ft_putendl_fd(line + 1, 2);
		else
		{
			if (!(ft_bool_strchr(line, ' ')) && !(ft_bool_strchr(line, '-')))
				ft_error(d, "Wrong input");
			if (ft_bool_strchr(line, ' '))
				get_room(d, line);
			if (ft_bool_strchr(line, '-'))
				get_path(d, line);
		}
		ft_strdel(&line);
	}
}

void	init_data(t_data *d)
{
	d->r = NULL;
	d->sol = NULL;
	d->p = NULL;
	d->s = NULL;
	d->t = NULL;
	d->best = NULL;
	d->mark = NULL;
	d->max = NULL;
	d->start = -1;
	d->end = -1;
	d->ants = 0;
	d->rooms = 0;
	d->lmax = 0;
	d->len = 0;
	d->x = 0;
	d->y = 0;
}

void	check_data(t_data *d)
{
	if (!(d->ants > 0 && d->ants <= INT_MAX))
		ft_error(d, "Wrong ants nbr");
	if (d->start == d->end || d->start < 0 || d->end < 0)
		ft_error(d, "Error with start/end");
	if (d->lmax == 0)
		ft_error(d, "Wrong path");
}

int		check_opt(const char c)
{
	const char	flag[6] = "drpsba";
	int			i;

	i = -1;
	while (++i < 6)
	{
		if (c == flag[i])
			return (1);
	}
	return (0);
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

int		graph_opt(char *av, int graph)
{
	int i;

	if (av[0] == '-')
	{
		i = 1;
		while (av[i])
		{
			if (check_opt(av[i]) == 0)
				bad_arg();
			graph = av[i] == 'd' ? graph | DATA : graph;
			graph = av[i] == 'r' ? graph | ROOM : graph;
			graph = av[i] == 'p' ? graph | PATH : graph;
			graph = av[i] == 's' ? graph | SOLV : graph;
			graph = av[i] == 'b' ? graph | BEST : graph;
			graph = av[i] == 'a' ? graph | ALL : graph;
			i++;
		}
		return (graph);
	}
	else
		bad_arg();
}

int		main(int ac, char **av)
{
	t_data	d;
	int		graph;
	int		i;

	i = 0;
	graph = 0;
	if (ac == 1)
		bad_arg();
	if (ac > 2)
	{
		while (++i < ac - 1)
			graph = graph_opt(av[i], 0);
	}
	init_data(&d);
	parser(&d, av[ac - 1]);
	check_data(&d);
	pathfinding(&d);
	if (graph)
		display(&d, graph);
	// display_solution(&d);
	ft_free(&d);
	return (0);
}
