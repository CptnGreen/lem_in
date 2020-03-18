#include "lem-in.h"

int		check_link(t_farm *farm, char const *src, char const *dst)
{
	t_room	*room;
	t_room	*room_src;
	t_room	*room_dst;
	int		is_checked_src;
	int		is_checked_dst;

	if (ft_strequ(src, dst))
	{
		perror("lem-in: Loop-link found; Aborting.\n");
		return (KO);
	}
	is_checked_src = 0;
	is_checked_dst = 0;
	room = farm->rooms;
	while (room)
	{
		if (!is_checked_src && ft_strequ(src, room->name))
		{
			room_src = room;
			is_checked_src = 1;
		}
		if (!is_checked_dst && ft_strequ(dst, room->name))
		{
			room_dst = room;
			is_checked_dst = 1;
		}
		if (is_checked_src && is_checked_dst)
		{
			farm->adj_matrix[room_src->num][room_dst->num] = '1';
			farm->adj_matrix[room_dst->num][room_src->num] = '1';
			return (OK);
		}
		room = room->next;
	}
	perror("lem-in: Corrupt link found - src or dst was never declared; Aborting.\n");
	return (KO);
}

int		append_link(t_farm *farm, char const *src, char const *dst)
{
	t_link		*link;
	t_link		*prev;

	if (check_link(farm, src, dst) != OK)
		return (KO);
	prev = farm->links;
	link = farm->links;
	while (link)
	{
		prev = link;
		link = link->next;
	}
	link = init_link(src, dst);
	if (farm->links)
		prev->next = link;
	else
		farm->links = link;
	return (OK);
}

int		get_new_link(int fd, t_farm *farm, char **line)
{
	char		**split;

	while ((*line)[0] == '#')
	{
		ft_strdel(line);
		if (!(get_next_line(fd, line) > 0))
		{
			printf("Reached end of the input. Last line is a comment.\n");
			return (OK);
		}
	}
	split = ft_strsplit(*line, '-');
	ft_strdel(line);
	if (!split[0] || !split[1] || split[2])
	{
		wipe_mstr(split);
		perror("lem-in: Wrong link declaration found; Aborting.\n");
		return (KO);
	}
	if (!(append_link(farm, split[0], split[1])))
	{
		wipe_mstr(split);
		return (KO);
	}
	wipe_mstr(split);
	return (OK);
}

int		get_links(int fd, t_farm *farm, char **line)
{
	if (get_new_link(fd, farm, line) == KO)
		return (KO);
	while (get_next_line(fd, line) > 0)
	{
		if (get_new_link(fd, farm, line) == KO)
			return (KO);
	}
	printf("Successfully reached end of the input; Printing links:\n");
	print_links(farm->links);
	printf("Adjacency matrix:\n");
	print_mstr(farm->adj_matrix);
	return (OK);
}
