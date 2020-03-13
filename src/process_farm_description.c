#include "lem-in.h"

int			find_n_ants(int fd, t_farm *farm)
{
    char		*line;

    line = NULL;
    while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '#')
        {
            ft_strdel(&line);
            continue ;
        }
        if ((farm->n_ants = ft_atoi(line)) > 0)
        {
            ft_strdel(&line);
			printf("n_ants = %d\n", farm->n_ants); // remove later!
            return (1);
        }
        ft_strdel(&line);
        perror("lem_in: Number of ants equals 0.\n");
        return (0);
    }
    perror("lem_in: Couldn't find number of ants.\n");
    return (0);
}

int			find_start_header(int fd)
{
    char		*line;

    line = NULL;
    while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '#')
        {
            if (ft_strnstr(line, "##start", ft_strlen("##start")) != 0)
            {
                ft_strdel(&line);
				printf("Successfully found start header!\n"); // remove later!
                return (1);
            }
        }
        ft_strdel(&line);
    }
    perror("lem_in: Couldn't find \"start\" identifier.\n");
    return (0);
}

int			get_room(int fd, t_farm *farm)
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
			(farm->rooms) = get_new_room(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
            wipe_mstr(split);
			printf("New room: name = \"%s\", x = %d, y = %d\n", \
				   (farm->rooms)->name, (farm->rooms)->x, (farm->rooms)->y);
			break ;
        }
    }
	return (1);
}

int			process_farm_description(int fd, t_farm *farm)
{
    if (!(find_n_ants(fd, farm) && \
          find_start_header(fd) && \
          get_room(fd, farm)))
	{
		perror("lem_in: Description is wrong - aborting.\n");
		return (0);
	}
	return (1);
}
