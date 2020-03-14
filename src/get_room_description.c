#include "lem-in.h"

int			get_room_description(int fd, t_farm *farm)
{
    char		*line;
    char		**split;
	int			i;

    line = NULL;
    split = NULL;
	i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '#')
        {
            ft_strdel(&line);
            continue ;
        }
        split = ft_strsplit(line, ' ');
        ft_strdel(&line);
		while (split[i])
			i += 1;
        if (i != 3)
        {
            perror("lem_in: Number of fields in the description of the room is not 3.\n");
            wipe_mstr(split);
            return (0);
        }
        else
        {
            while (farm->rooms)
                (farm->rooms) = (farm->rooms)->next;
			(farm->rooms) = init_room(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
            wipe_mstr(split);
			printf("New room: name = \"%s\", x = %d, y = %d\n", \
				   (farm->rooms)->name, (farm->rooms)->x, (farm->rooms)->y);
			break ;
        }
    }
	return (1);
}
