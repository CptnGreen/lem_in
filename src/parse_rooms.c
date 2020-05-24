#include "lem-in.h"
#include "libft.h"

int			build_room_ar(t_farm *farm)
{
	t_room		*room;

	room = farm->rooms;
	if (!(farm->room_ar = (t_room **)ft_memalloc(sizeof(t_room *) * (farm->n_rooms + 1))))
		return (KO);
	while (room)
	{
		farm->room_ar[room->num] = room;
		room = room->next;
	}
	farm->room_ar[farm->n_rooms] = NULL;
	ft_putstr_fd("build_room_ar(): Array of rooms is built.\n", farm->log_fd);
	return (OK);
}

int			handle_no_more_rooms(t_farm *farm, char **split, char **line)
{
	wipe_mstr(split);
	ft_putstr_fd("handle_no_more_rooms(): Reached end of rooms' declarations. Starts: ", farm->log_fd);
	ft_putnbr_fd(farm->start_counter, farm->log_fd);
	ft_putstr_fd(", ends: ", farm->log_fd);
	ft_putnbr_fd(farm->end_counter, farm->log_fd);
	ft_putstr_fd("\n", farm->log_fd);
	if (farm->start_counter != 1 || farm->end_counter != 1)
	{
		ft_putstr_fd("handle_no_more_rooms(): Wrong number of start or end headers; Aborting.\n", farm->log_fd);
		ft_strdel(line);
		return (KO);
	}
	if (!(farm->adj_matrix = get_matrix_of_char(farm->n_rooms, farm->n_rooms, '0')) || \
		build_room_ar(farm) == KO)
		return (KO);
	farm->end_room->n_ants = farm->n_ants;
	ft_putstr_fd("handle_no_more_rooms(): Adjacency matrix initialized.\n", farm->log_fd);
	return (OK);
}

/*
** Called from process_farm_description()
*/

int			parse_rooms(t_farm *farm, t_input_line **input_passed)
{
    char			**split;
	int				res;
	int				is_start;
	int				is_end;
	t_room			*room;
	t_input_line	*input;
	char			*line;
	int				i;

	i = 0;
    split = NULL;
	res = 0;
	is_start = 0;
	is_end = 0;
	input = (*input_passed)->next;
    while (input)
    {
		line = ft_strdup(input->line);
        if (line[0] == '#')
        {
			if ((res = handle_start_and_end_headers(farm, &line)) != COMMENT_FOUND)
			{
				is_start = ((res == START_HEADER_IS_FOUND) ? (1) : (0));
				is_end = ((res == END_HEADER_IS_FOUND) ? (1) : (0));
			}
			ft_strdel(&line);
			input = input->next;
			continue ;
		}
		split = ft_strsplit(line, ' ');
        if (!split[0] || !split[1] || !split[2] || split[3])
		{
			if (split[0] && split[1] && split[2] && split[3])
			{
				ft_putstr_fd("parse_rooms(): Too many coords given - aborting.\n", farm->log_fd);
				return (KO);
			}
			*input_passed = input;
			return ((handle_no_more_rooms(farm, split, &line) == OK) ? (OK) : (KO));
		}
        else
        {
			ft_strdel(&line);
			i = 0;
			while (split[1][i])
			{
				if (split[1][i] < '0' || split[1][i] > '9')
				{
					ft_putstr_fd("parse_rooms(): Letter as the coordinate - aborting.\n", farm->log_fd);
					return (KO);
				}
				i += 1;
			}
			i = 0;
			while (split[2][i])
			{
				if (split[2][i] < '0' || split[2][i] > '9')
				{
					ft_putstr_fd("parse_rooms(): Letter as the coordinate - aborting.\n", farm->log_fd);
					return (KO);
				}
				i += 1;
			}
			if ((room = init_and_append_room(farm, split[0], ft_atoi(split[1]), ft_atoi(split[2]))))
			{
				room->is_start = ((is_start) ? (1) : (0));
				if (is_start)
					farm->start_room = room;
				if (is_end)
					farm->end_room = room;
				room->is_end = ((is_end) ? (1) : (0));
				is_start = 0;
				is_end = 0;
			}
            wipe_mstr(split);
			input = input->next;
			continue ;
        }
    }
	ft_strdel(&line);
	ft_putstr_fd("parse_rooms(): Reached end of file, but no links were found; Aborting.\n", farm->log_fd);
	return (KO);
}
