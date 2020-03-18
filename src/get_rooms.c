#include "lem-in.h"

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
	return (OK);
}

int			handle_no_more_rooms(t_farm *farm, char **split, char **line)
{
	wipe_mstr(split);
	printf("Reached end of rooms' declarations. Starts: %d, ends: %d\n", \
		   farm->start_counter, farm->end_counter);
	if (farm->start_counter != 1 || farm->end_counter != 1)
	{
		perror("lem-in: Wrong number of start or end headers; Aborting.\n");
		ft_strdel(line);
		return (KO);
	}
	if (!(farm->adj_matrix = get_matrix_of_char(farm->n_rooms, farm->n_rooms, '0')) || \
		build_room_ar(farm) == KO)
		return (KO);
	printf("Adjacency matrix initialized, array of rooms is built.\n");
	print_rooms(farm->rooms);
	return (OK);
}

int			get_rooms(int fd, t_farm *farm, char **line)
{
    char		**split;
	int			res;

    split = NULL;
	res = 0;
    while (get_next_line(fd, line) > 0)
    {
        if ((*line)[0] == '#')
        {
			if ((res = handle_start_and_end_headers(fd, farm, line)) != HEADER_NOT_FOUND)
				return (res);
            ft_strdel(line);
            continue ;
        }
        split = ft_strsplit(*line, ' ');
        if (!split[0] || !split[1] || !split[2] || split[3])
			return ((handle_no_more_rooms(farm, split, line) == OK) ? (OK) : (KO));
        else
        {
			ft_strdel(line);
			append_room(farm, split[0], ft_atoi(split[1]), ft_atoi(split[2]));
            wipe_mstr(split);
			continue ;
        }
    }
	ft_strdel(line);
	perror("lem-in: Reached end of file, but no links were found; Aborting.\n");
	return (OK);
}
