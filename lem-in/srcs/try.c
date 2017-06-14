// void	get_ways(t_data *data, int room, int turn, int try)
// {
// 	t_queue	*f;
// 	t_pos	i;
// 	int		p = 0;

// 	if (!(f = (t_queue *)ft_memalloc(sizeof(t_queue *))))
// 		ft_error(data, "Error malloc");
// 	f->first = NULL;
// 	ft_enqueue(f, room);
// 	data->mark[room] = p;
// 	while (f->first != NULL)
// 	{
// 		display_queue(f);
// 		i.y = ft_dequeue(f);
// 		data->s[try][turn++] = i.y;
// 		p++;
// 		i.x = -1;
// 		while (++i.x < data->rooms)
// 		{
// 			if (data->p[i.y][i.x] > 0)
// 			{
// 				if (data->mark[i.x] == INT_MAX)
// 				{
// 					ft_enqueue(f, i.x);
// 					data->mark[i.x] = p;
// 				}
// 			}
// 		}
// 	}
// }
