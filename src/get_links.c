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
		ft_putstr_fd("Loop-link found; Aborting.\n", farm->log_fd);
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
	ft_putstr_fd("Corrupt link found - src or dst was never declared; Aborting.\n", farm->log_fd);
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
	link = init_link(farm, src, dst);
	if (farm->links)
		prev->next = link;
	else
		farm->links = link;
	return (OK);
}

int		get_new_link(t_farm *farm, int fd, char **line)
{
	char		**split;

	while ((*line)[0] == '#')
	{
		ft_strdel(line);
		if (!(get_next_line(fd, line) > 0))
			return (OK);
	}
	split = ft_strsplit(*line, '-');
	ft_strdel(line);
	if (!split[0] || !split[1] || split[2])
	{
		wipe_mstr(split);
		ft_putstr_fd("Wrong link declaration found; Aborting.\n", farm->log_fd);
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

int		get_links(t_farm *farm, int fd, char **line)
{
	if (get_new_link(farm, fd, line) == KO)
		return (KO);
	while (get_next_line(fd, line) > 0)
	{
		if (get_new_link(farm, fd, line) == KO)
			return (KO);
	}
	ft_putstr_fd("Successfully reached end of the input.\n", farm->log_fd);
	return (OK);
}
