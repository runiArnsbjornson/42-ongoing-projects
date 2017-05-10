/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:47:40 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/10 18:12:11 by jdebladi         ###   ########.fr       */
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
		data->a = data->room->next;
		free(tmp);
	}
	while (data->b)
	{
		free(data->b->content)
		tmp = data->a;
		data->a = data->a->next;
		free(tmp);
	}
	while (data->c)
	{
		free(data->c->content)
		tmp = data->a;
		data->a = data->a->next;
		free(tmp);
	}
}

void	ft_error(t_data *data, char *str)
{
	ft_putstr_fd(RED "ERROR", 2);
	if (str)
	{
		ft_putstr_fd(RES " : ", 2);
		ft_putendl_fd(str);
	}
	ft_free(data);
	exit(0);
}

void	get_ants_nbr(t_data *data, char **res)
{
	char	*line;

	if (ft_gnl(0, &line) > 0)
	{
		if (!(ft_lstaddend(data->f, ft_lstnew(line, ft_strlen(line) + 1))))
			ft_error(data, "Error malloc");
		data->ants = ft_atoi(line);
		free(line);
		if (data->ants < 1)
			ft_error(data, "Bad ants nbr");
	}
}

void	get_room(t_data *data)
{
	if (data->ants)
	{

	}
}

void	room_name()

void	get(t_data *data, char *line)
{
	if (ft_bool_strchr(line, '-'))
		return ;
	if (*line != 'L')
	{
		if (!(room_name(data->room, line) && ))
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
				data->start = 1;
			if (ft_strcmp(line + 2, "end") == 0)
				data->end = 1;
			else
				ft_error(data, "wrong room");
		}
		else if (ft_strncmp(line, "#", 1) == 0)
			ft_putendl_fd(line + 1, 2);
		else
			get(data, line);
	}
}

int		main(void)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		MERROR
	data->a = NULL;
	data->b = NULL;
	data->c = NULL;
	data->ants = 0;
	data->paths = 0;
	parser(data);
	return (0);
}