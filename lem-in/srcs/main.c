/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:47:40 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 10:12:50 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	ft_free(t_data *data)
{
	t_list *tmp;

	while (data->room)
	{
		tmp = data->room;
		data->room = data->room->next;
		free(tmp);
		tmp = NULL;
	}
	while (data->path)
	{
		tmp = data->path;
		data->path = data->path->next;
		free(tmp);
		tmp = NULL;
	}
	free(data);
	data = NULL;
}

void	display(t_data *data)
{
	t_list *save;

	save = data->room;
	while (data->room)
	{
		if (((t_room *)(data->room->content))->type == 1)
			ft_putendl("entrance");
		if (((t_room *)(data->room->content))->type == 2) 
			ft_putendl("exit");
		ft_putendl(((t_room *)(data->room->content))->name);
		data->room = data->room->next;
	}
	data->room = save;
	save = data->path;
	while (data->path)
	{
		ft_putstr(((t_path *)(data->path->content))->r1);
		ft_putstr("<=>");
		ft_putendl(((t_path *)(data->path->content))->r2);
		data->path = data->path->next;
	}
	data->path = save;
}

void	ft_error(char *str)
{
	ft_putstr_fd(RED "ERROR", 2);
	if (str)
	{
		ft_putstr_fd(RES " : ", 2);
		ft_putendl_fd(str, 2);
	}
	exit(0);
}

void	get_ants_nbr(t_data *data)
{
	char	*line;

	if (ft_gnl(0, &line) > 0)
	{
		if (!line)
			ft_error("error gnl");
		data->ants = ft_atoi(line);
		if (data->ants < 1)
			ft_error("Bad ants nbr");
		free(line);
	}
}

void	get_path(t_data *data, char *line)
{
	t_path		*path;

	if (ft_bool_strchr(line, '-') == 0)
		return ;
	if (line != NULL)
	{
		path = malloc(sizeof(t_path));
		path->r1 = ft_strccpy(line, '-');
		path->r2 = ft_strchr(line, '-') + 1;
		ft_lstaddend(&(data->path), ft_lstnew(path, sizeof(t_path)));
		free(path);
	}
}

void	get_room(t_data *data, char *line)
{
	t_room	*room;

	if (ft_bool_strchr(line, '-'))
		return ;
	if (line != NULL)
	{
		room = malloc(sizeof(t_room));
		room->name = ft_strccpy(line, ' ');
		room->ant = 0;
		if (data->start || data->end)
			room->type = data->start == 1 ? 1 : 2;
		else
			room->type = 0;
		room->pos.x = ft_atoi(ft_strchr(line, ' '));
		room->pos.y = ft_atoi(ft_strrchr(line, ' '));
		ft_lstaddend(&(data->room), ft_lstnew(room, sizeof(t_room)));
		free(room);
	}
}

void	clean_type(t_data *data)
{
	data->start = 0;
	data->end = 0;
}

void	parser(t_data *data)
{
	char *line;

	get_ants_nbr(data);
	while (ft_gnl(0, &line))
	{
		if (ft_strncmp(line, "##", 2) == 0)
		{
			if (ft_strcmp(line + 2, "start") == 0)
				data->start = 1;
			else if (ft_strcmp(line + 2, "end") == 0)
				data->end = 1;
			else
				ft_error("wrong room");
		}
		else if (ft_strncmp(line, "#", 1) == 0)
			ft_putendl_fd(line + 1, 2);
		else
		{
			get_room(data, line);
			get_path(data, line);
			clean_type(data);
		}
		free(line);
	}
}

int		main(int ac, char **av)
{
	t_data	*data;
	static int	graph = 0;

	if (ac != 1)
	{
		if (ft_strcmp(av[1], "-g") == 0)
			graph = 1;
	}
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		perror("Error malloc");
	data->room = NULL;
	data->path = NULL;
	data->start = 0;
	data->end = 0;
	data->ants = 0;
	data->paths = 0;
	parser(data);
	graph ? display(data) : 0;
	//pathfinding(data);
	ft_free(data);
	return (0);
}