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

int		parse_next_link(t_farm *farm, t_input_line *input)
{
	char		**split;

	while ((input->line)[0] == '#')
	{
		input = input->next;
		if (!(input))
			return (OK);
	}
	/* printf("parse_next_link(): %s\n", input->line); */
	split = ft_strsplit(input->line, '-');
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

/*
** This function is called in process_farm_description()
** after parse_n_ants() and parse_rooms().
*/

int		parse_links(t_farm *farm, t_input_line **input)
{
	if (parse_next_link(farm, *input) == KO)
		return (KO);
	while ((*input)->next)
	{
		*input = (*input)->next;
		if (parse_next_link(farm, (*input)) == KO)
			return (KO);
	}
	ft_putstr_fd("parse_links(): Reached end of input.\n", farm->log_fd);
	/* print_links(farm->links); */
	return (OK);
}
