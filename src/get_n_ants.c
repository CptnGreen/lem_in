#include "lem-in.h"

int			get_n_ants(t_farm *farm, t_input_line *input, char **line)
{
    while (input)
    {
		*line = ft_strdup(input->line);
		input = input->next;
        if ((*line)[0] == '#')
        {
            ft_strdel(line);
            continue ;
        }
        if ((farm->n_ants = ft_atoi(*line)) > 0)
        {
            ft_strdel(line);
            return (OK);
        }
        ft_strdel(line);
        ft_putstr_fd("Number of ants equals 0.\n", farm->log_fd);
        return (KO);
    }
    ft_putstr_fd("Couldn't find number of ants.\n", farm->log_fd);
    return (KO);
}
