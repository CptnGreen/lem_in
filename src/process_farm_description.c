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

int			get_start_room(int fd, t_farm *farm)
{
	if (get_room_description(fd, farm))
	{
		farm->rooms->is_start = 1;
		return (1);
	}
	perror("lem_in: Start room declared but not present.\n");
	return (0);
}

int			get_another_rooms(int fd, t_farm *farm)
{
}

int			process_farm_description(int fd, t_farm *farm)
{
    if (!(find_n_ants(fd, farm) && \
          find_start_header(fd) && \
          get_start_room(fd, farm) && \
		  get_another_rooms(fd, farm)))
		return (0);
	return (1);
}
