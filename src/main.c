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

int			process_farm_description(int fd, t_farm *farm)
{
	char	*line;
	int		i;

	line = NULL;
    if (get_n_ants(farm, fd, &line) != OK || \
		get_rooms(farm, fd, &line) != OK || \
		get_links(farm, fd, &line) != OK)
		return (KO);
	i = 0;
	while (assign_depth(farm) != NO_MORE_PATHS_FOUND)
		i += 1;
	if (i == 0)
		return (KO);
	make_ants(farm);
	ft_putstr_fd("Farm description successfully processed.\n", farm->log_fd);
	return (OK);
}

int		main(void)
{
	t_farm	farm;

	if (init_farm(&farm) && \
		process_farm_description(FD, &farm))
	{
		print_farm_description(&farm);
		/* print_farm_description_v(&farm); */
		lem_in(&farm);
		sleep();
		return (OK);
	}
	printf("ERROR\n");
	sleep();
	return (KO);
}
