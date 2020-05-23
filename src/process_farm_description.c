#include "lem-in.h"

int			make_ants(t_farm *farm)
{
	int		i;
	t_ant	*a;

	i = 0;
	while (i < farm->n_ants)
	{
		init_and_append_ant(farm, i + 1);
		i += 1;
	}
	a = farm->ants;
	while (a)
	{
		enqueue_ant(&(farm->start_room->ants), a);
		a = a->next;
	}
	return (OK);
}

int			process_farm_description(t_input_line *input, t_farm *farm)
{
	char	*line;
	int		i;

	line = NULL;
	if (parse_n_ants(farm, input, &line) != OK || \
		parse_rooms(farm, &input, &line) != OK ||	\
		parse_links(farm, input) != OK)
		return (KO);
	/* printf("%s\n", input->line); */
	i = 0;
	while (assign_depth(farm) != NO_MORE_PATHS_FOUND)
		i += 1;
	/* if (i == 0) */
	/* 	return (KO); */
	make_ants(farm);
	ft_putstr_fd("process_farm_description(): Success.\n", farm->log_fd);
	return (OK);
}
