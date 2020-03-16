#include "lem-in.h"

int			get_n_ants(int fd, t_farm *farm, char **line)
{
    while (get_next_line(fd, line) > 0)
    {
        if ((*line)[0] == '#')
        {
            ft_strdel(line);
            continue ;
        }
        if ((farm->n_ants = ft_atoi(*line)) > 0)
        {
            ft_strdel(line);
			printf("n_ants = %d\n", farm->n_ants); // remove later!
            return (OK);
        }
        ft_strdel(line);
        perror("lem_in: Number of ants equals 0.\n");
        return (KO);
    }
    perror("lem_in: Couldn't find number of ants.\n");
    return (KO);
}
