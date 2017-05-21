/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:47:40 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/21 18:12:45 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

// void	ft_free(t_data *data)
// {
// 	t_list *tmp;

// 	while (data->r)
// 	{
// 		tmp = data->r;
// 		data->r = data->r->next;
// 		free(tmp);
// 		tmp = NULL;
// 	}
// 	while (data->path)
// 	{
// 		tmp = data->path;
// 		data->path = data->path->next;
// 		free(tmp);
// 		tmp = NULL;
// 	}
// 	free(data);
// 	data = NULL;
// }

// void	display(t_data *data)
// {
// 	t_list *save;

// 	save = data->r;
// 	while (data->r)
// 	{
// 		if (((t_room *)(data->r->content))->type == 1)
// 			ft_putendl("entrance");
// 		if (((t_room *)(data->r->content))->type == 2) 
// 			ft_putendl("exit");
// 		ft_putendl(((t_room *)(data->r->content))->name);
// 		data->r = data->r->next;
// 	}
// 	data->r = save;
// 	save = data->path;
// 	while (data->path)
// 	{
// 		ft_putstr(((t_path *)(data->path->content))->r1);
// 		ft_putstr("<=>");
// 		ft_putendl(((t_path *)(data->path->content))->r2);
// 		data->path = data->path->next;
// 	}
// 	data->path = save;
// }

void	ft_error(t_data *data, char *str)
{
	ft_put_error(str);
	ft_free(data);
	exit(0);
}

void	get_ants_nbr(t_data *data)
{
	char	*line;

	if (ft_gnl(0, &line) > 0)
	{
		if (!line)
			ft_put_error("Bad ants input");
		data->ants = ft_atoi(line);
		if (!(data->ants > 1 && data->ants <= INT_MAX))
			ft_put_error("Wrong ants nbr");
		ft_strdel(&line);
	}
}

void	check_path(t_data *data, t_list *tmp, char *r1, char *r2)
{
	int i;
	int check;

	i = 1;
	check = 0;
	while (tmp)
	{
		if (!(ft_strcmp(r1 , tmp->content)))
		{
			data->y = i;
			check++;
		}
		if (!(ft_strcmp(r2 , tmp->content)))
		{
			data->x = i;
			check++;
		}
		tmp = tmp->next;
		i++;
	}
	if (check != 2 || data->x == data->y)
		ft_error(data, "Error with start/exit");
}

void	get_path(t_data *data, char *line)
{
	char		*r1;
	int			i;
	t_list		*tmp;
	static int	p = 1;

	i = -1;
	r1 = ft_strccpy(line, '-');
	if (data->paths == 0)
	{
		if (!(data->paths = (int **)ft_memalloc(sizeof(int *) * ft_pwr(data->rooms + 1, 2))))
			ft_error(data, "Error malloc");
		while (++i < data->rooms)
		{
			if (!(data->paths[i] = (int *)ft_memalloc(sizeof(int) * (data->rooms + 1))))
				ft_error(data, "Error malloc");
		}
	}
	tmp = data->r;
	check_path(data, tmp, r1, ft_strchr(line, '-') + 1);
	data->paths[data->y][data->x] = p;
	data->paths[data->x][data->y] = p++;
	ft_strdel(&r1);
}

void	get_room(t_data *data, char *line)
{
	char *r;
	t_list *tmp;

	r = ft_strccpy(line, ' ');
	if (!(tmp = ft_lstnew(r, ft_strlen(r + 1))))
		ft_error(data, "Error malloc");
	ft_lstaddend(&data->r, tmp);
	data->rooms++;
	if (data->start == 0)
		data->start = data->rooms;
	else if (data->end == 0)
		data->end = data->rooms;
	free(&tmp);
	free(&r);
}

void	get_type(t_data *data, char *line)
{
	if (ft_strcmp(line + 2, "start") == 0 || data->start == -1)
		data->start = 0;
	else if (ft_strcmp(line + 2, "end") == 0 || data->end == -1)
		data->end = 0;
	else
		ft_error(data, "Bad strart/end input");
	ft_strdel(&line);
}

void	parser(t_data *data)
{
	char *line;

	get_ants_nbr(data);
	while (ft_gnl(0, &line) > 0)
	{
		if (!*line)
			ft_put_error("Bad input");
		if (ft_strncmp(line, "##", 2) == 0)
			get_type(data, line);
		else if (ft_strncmp(line, "#", 1) == 0)
			ft_putendl_fd(line + 1, 2);
		else
		{
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
	data->paths = NULL;
	data->start = -1;
	data->end = -1;
	data->ants = 0;
	data->rooms = 0;
}

int		main(int ac, char **av)
{
	t_data	data;
	static int	graph = 0;

	if (ac != 1)
	{
		if (ft_strcmp(av[1], "-g") == 0)
			graph = 1;
	}
	init_data(&data);
	parser(&data);
	if (graph)
		display(&data);
	//pathfinding(data);
	return (0);
}
