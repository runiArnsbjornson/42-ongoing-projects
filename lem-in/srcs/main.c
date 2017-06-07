/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:47:40 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/02 17:20:30 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	display_rooms(t_data *data, t_list *tmp, int i)
{
	ft_printf(GRN "List of rooms :\n" RES);
	while (data->r)
	{
		ft_printf("%d : %s", i, data->r->content);
		if (i == data->start - 1)
			ft_printf(" << entrance\n");
		else if (i == data->end - 1)
			ft_printf(" << exit\n");
		else
			ft_printf("\n");
		data->r = data->r->next;
		i++;
	}
	data->r = tmp;
}

void	display_data(t_data *data, t_list *tmp, int i)
{
	ft_printf("%s\nThere are %d rooms\n", BLU "Data parsed :" RES, data->rooms);
	while (data->r && i < data->start - 1)
	{
		data->r = data->r->next;
		i++;
	}
	ft_printf("%d ant%s in the anthill\n", data->ants, data->ants == 1 ? " is" : "s are");
	ft_printf("starting room is : %s\n", data->r->content);
	data->r = tmp;
	i = 0;
	while (data->r && i < data->end - 1)
	{
		data->r = data->r->next;
		i++;
	}
	ft_printf("exit is in room : %s\n", data->r->content);
	data->r = tmp;
}

void	display_best(t_data *data, t_list *tmp, int i)
{
	int j;

	if (data->best[0] == data->best[1])
		ft_error(data, "No solution found");
	else
	{
		while (++i < data->rooms)
		{
			j = data->best[i];
			i == 0 ? ft_printf(BOL "Best solution :\n" RES) : 0;
			while (data->r && j--)
				data->r = data->r->next;
			ft_printf("%s%s", data->r->content, data->best[i] == data->end - 1 ? "\n" : " -> ");
			data->r = tmp;
			if (data->best[i] == data->end - 1)
				break ;
		}
	}
}

void	display(t_data *data, int type)
{
	t_list	*tmp;

	tmp = data->r;
	if (!!(type & (DATA << 0)) || (!!(type & (ALL << 0))))
		display_data(data, tmp, 0);
	if (!!(type & (ROOM << 0)) || (!!(type & (ALL << 0))))
		display_rooms(data, tmp, 0);
	if (!!(type & (PATH << 0)) || (!!(type & (ALL << 0))))
	{
		ft_printf(MAG "Matrix of paths :\n" RES);
		ft_putinttab(data->t, data->rooms);
	}
	if (!!(type & (SOLV << 0)) || (!!(type & (ALL << 0))))
	{
		ft_printf(YEL "Matrix of solution(s) :\n" RES);
		ft_putinttab(data->s, data->rooms);
	}
	if (!!(type & (BEST << 0)) || (!!(type & (ALL << 0))))
		display_best(data, tmp, -1);
}

void	ft_free(t_data *data)
{
	if (data->r != NULL)
		ft_lstfree(&data->r);
	if (data->p != NULL)
		ft_inttabdel(data->p, data->rooms);
	if (data->s != NULL)
		ft_inttabdel(data->s, data->rooms);
	if (data->t != NULL)
		ft_inttabdel(data->t, data->rooms);
	// if (data->best != NULL)
		// ft_inttabdel(&data->best, 1);
	data = NULL;
}

void	ft_error(t_data *data, char *str)
{
	ft_put_error(str);
	ft_free(data);
	exit(0);
}

void	get_ants_nbr(t_data *data)
{
	char	*line;

	if (gnl(0, &line) > 0)
	{
		if (!line)
			ft_error(data, "Bad ants input");
		data->ants = ft_atoi(line);
		if (!(data->ants > 0 && data->ants <= INT_MAX))
			ft_error(data, "Wrong ants nbr");
		ft_strdel(&line);
	}
}

void	check_path(t_data *data, t_list *tmp, char *r1, char *r2)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (tmp)
	{
		if (ft_strcmp(r1, (char *)tmp->content) == 0)
		{
			data->y = i;
			check++;
		}
		if (ft_strcmp(r2, (char *)tmp->content) == 0)
		{
			data->x = i;
			check++;
		}
		tmp = tmp->next;
		i++;
	}
	if (check != 2 || data->x == data->y)
		ft_error(data, "Error with path");
}

void	get_path(t_data *data, char *line)
{
	char		*r1;
	t_list		*tmp;
	static int	p = 1;

	r1 = ft_strccpy(line, '-');
	if (data->p == NULL)
		if (!(data->p = ft_inttab(data->rooms, data->rooms)) ||
		!(data->t = ft_inttab(data->rooms, data->rooms)))
			ft_error(data, "Error malloc");
	tmp = data->r;
	check_path(data, tmp, r1, ft_strchr(line, '-') + 1);
	data->t[data->y][data->x] = p;
	data->t[data->x][data->y] = p;
	data->p[data->y][data->x] = p;
	data->p[data->x][data->y] = p++;
	ft_strdel(&r1);
}

void	check_rooms(t_data *data, char *r)
{
	t_list *tmp;

	tmp = data->r;
	while (tmp)
	{
		if (ft_strcmp(r, tmp->content) == 0)
			ft_error(data, "Wrong room name");
		tmp = tmp->next;
	}
}

void	get_room(t_data *data, char *line)
{
	char	*r;
	t_list	*tmp;

	r = ft_strccpy(line, 32);
	check_rooms(data, r);
	if ((tmp = ft_lstnew(r, ft_strlen(r))) == NULL)
		ft_error(data, "Error malloc");
	ft_lstaddend(&data->r, tmp);
	data->rooms++;
	if (data->start == 0)
		data->start = data->rooms;
	if (data->end == 0)
		data->end = data->rooms;
	ft_strdel(&r);
}

void	get_type(t_data *data, char *line)
{
	if (ft_strcmp(line, "##start") == 0 && data->start == -1)
		data->start = 0;
	else if (ft_strcmp(line, "##end") == 0 && data->end == -1)
		data->end = 0;
	else
		ft_error(data, "Wrong ## input");
}

void	parser(t_data *data)
{
	char *line;

	get_ants_nbr(data);
	while (gnl(0, &line) > 0)
	{
		if (!*line)
			break ;
		if (ft_strncmp(line, "##", 2) == 0)
			get_type(data, line);
		else if (*line == '#')
			ft_putendl_fd(line + 1, 2);
		else
		{
			if (!(ft_bool_strchr(line, ' ')) && !(ft_bool_strchr(line, '-')))
				ft_error(data, "Wrong input");
			if (ft_bool_strchr(line, ' '))
				get_room(data, line);
			if (ft_bool_strchr(line, '-'))
				get_path(data, line);
		}
		ft_strdel(&line);
	}
}

void	init_data(t_data *data)
{
	data->r = NULL;
	data->p = NULL;
	data->s = NULL;
	data->t = NULL;
	data->best = NULL;
	data->start = -1;
	data->end = -1;
	data->ants = 0;
	data->rooms = 0;
	data->len = 0;
	data->x = 0;
	data->y = 0;
}

void	check_data(t_data *data)
{
	if (data->start == data->end || data->start < 0 || data->end < 0)
		ft_error(data, "Error with start/end");
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
	ft_putendl_fd("usage: ./lem-in [-drpsba] < \033[04mfile\033[0m", 2);
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
	t_data	data;
	int		graph;
	int i;

	i = 0;
	graph = 0;
	while (++i < ac)
		graph = graph_opt(av[i], 0);
	init_data(&data);
	parser(&data);
	check_data(&data);
	pathfinding(&data);
	if (graph)
		display(&data, graph);
	display_solution(&data);
	ft_free(&data);
	return (0);
}
