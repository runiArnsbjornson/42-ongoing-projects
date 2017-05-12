/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:47:40 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/12 17:04:24 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	ft_free(t_data *data)
{
	t_room *tmp;

	while (data->room)
	{
		tmp = (t_room*)data->room->content;
		free(tmp->name);
		free(tmp);
		tmp = data->room;
		data->room = (t_room*)data->room->next;
		free(tmp);
	}
	while (data->path)
	{
		free(data->path->content)
		tmp = data->path;
		data->path = data->path->next;
		free(tmp);
	}
	while (data->c)
	{
		free(data->c->content);
		tmp = data->c;
		data->c = data->c->next;
		free(tmp);
	}
}

void	ft_error(t_data *data, char *str)
{
	ft_putstr_fd(RED "ERROR", 2);
	if (str)
	{
		ft_putstr_fd(RES " : ", 2);
		ft_putendl_fd(str, 2);
	}
	ft_free(data);
	exit(0);
}

void	get_ants_nbr(t_data *data)
{
	char	*line;

	if (ft_gnl(0, &line) > 0)
	{
		if (!line)
			ft_error(data, "error gnl");
		data->ants = ft_atoi(line);
		free(line);
		if (data->ants < 1)
			ft_error(data, "Bad ants nbr");
	}
}

void	get_path(t_data *data, char *line)
{
	t_path		path;
	char		**tmp;
	static int	nbr = 0;

	if (ft_bool_strchr(line, '-') == 0)
		return ;
	if (line)
	{
		tmp = ft_strsplit(line, '-');
		if (!tmp[0] || !tmp[1])
			ft_error(data, "error split");
		path.r1 = ft_atoi(tmp[0]);
		path.r2 = ft_atoi(tmp[1]);
		ft_lstaddend(data->path, ft_lstnew(path, sizeof(t_path)));
		
		ft_tabdel(tmp);
	}
}

void	get_room(t_data *data, char *line)
{
	t_room	room;
	char	**tmp;

	if (ft_bool_strchr(line, '-'))
		return ;
	if (line)
	{
		tmp = ft_strsplit(line, ' ');
		if (!tmp[0] || !tmp[1] || !tmp[2])
			ft_error(data, "error split");
		room.name = tmp[0];
		room.ant = 0;
		if (data->start || data->end)
		{
			room.type = data->start == 1 ? 1 : 2;
			data->start = 0;
			data->end = 0;
		}
		else
			room.type = 0;
		room.pos.x = ft_atoi(tmp[1]);
		room.pos.y = ft_atoi(tmp[2]);
		ft_lstaddend(data->room, ft_lstnew(room, sizeof(t_room)));
		ft_tabdel(tmp);
	}
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
				data->start += 1;
			if (ft_strcmp(line + 2, "end") == 0)
				data->end += 1;
			else
				ft_error(data, "wrong room");
		}
		else if (ft_strncmp(line, "#", 1) == 0)
			ft_putendl_fd(line + 1, 2);
		else
		{
			get_room(data, line);
			get_path(data, line);
		}
	}
}

int		main(void)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_error(data, "error malloc");
	data->room = NULL;
	data->path = NULL;
	data->c = NULL;
	data->start = 0;
	data->end = 0;
	data->ants = 0;
	data->paths = 0;
	parser(data);
	return (0);
}