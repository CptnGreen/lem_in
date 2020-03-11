#include "lem_in.h"

int			find_n_ants(int fd)
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
            return (1);
        }
        ft_strdel(&line);
        perror("lem_in: Number of ants equals 0.\n");
        return (0);
    }
    perror("lem_in: Couldn't find number of ants.\n");
    return (0);
}

int			find_start(int fd)
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

    line = NULL;
    split = NULL;
    while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '#')
        {
            ft_strdel(&line);
            continue ;
        }
        split = ft_strsplit(line, ' ');
        ft_strdel(&line);
        if (split[3])
        {
            wipe_mstr(split);
            perror("lem_in: Too many fields in the description of the room.\n");
            return (0);
        }
        else if (split[0] && split[1] && split[2])
        {
            while (farm->rooms)
                (farm->rooms) = (farm->rooms)->next;
			(farm->rooms)->next = get_new_room(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
        }
		else
		{
			perror("lem_in: Not enough fields in the description of the room.\n");
			return (0);
		}
    }
}

void		process_farm_description(t_farm *farm)
{
    if (!(find_n_ants(fd) && \
          find_start(fd) && \
            ))
}
