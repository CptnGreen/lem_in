#include "lem-in.h"

int			get_rooms(int fd, t_farm *farm, char **line)
{
    char		**split;
	int			res;
	int			i;

    split = NULL;
	i = 0;
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
		while (split[i])
			i += 1;
        if (i != 3)
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
			return (OK);
        }
        else
        {
			ft_strdel(line);
            while (farm->rooms)
                (farm->rooms) = (farm->rooms)->next;
			(farm->rooms) = init_room(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
            wipe_mstr(split);
			printf("New room: name = \"%s\", x = %d, y = %d\n", \
				   (farm->rooms)->name, (farm->rooms)->x, (farm->rooms)->y);
			continue ;
        }
    }
	ft_strdel(line);
	perror("lem-in: Reached end of file, but no links were found; Aborting.\n");
	return (OK);
}
