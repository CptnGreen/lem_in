#include "lem-in.h"

int			make_ants(t_farm *farm)
{
	int		i;
	t_ant	*a;

	i = 0;
	while (i < farm->n_ants)
	{
		init_and_append_ant(farm, i);
		i += 1;
	}
	a = farm->ants;
	while (a)
	{
		enqueue_ant(&(farm->start_room->ants), a);
		a = a->next;
	}
	/* print_room(farm->start_room); */
	return (OK);
}

int			process_farm_description(int fd, t_farm *farm)
{
	char	*line;
	int		i;

	line = NULL;
    if (get_n_ants(fd, farm, &line) != OK || \
		get_rooms(fd, farm, &line) != OK || \
		get_links(fd, farm, &line) != OK)
		return (KO);
	i = 0;
	while (assign_depth(farm) != NO_MORE_PATHS_FOUND)
		i += 1;
	if (i == 0)
		return (KO);
	/* printf("Gateways - last rooms (except for \"end\") in the found paths:\n"); */
	/* print_rooms_queue(farm->gateways); */
	make_ants(farm);
	/* printf("Farm description successfully processed.\n\n"); */
	lem_in(farm);
	return (OK);
}

int		main(void)
{
	t_farm	farm;

	freopen("stderr.log", "w", stderr);
	if (init_farm(&farm) && \
		process_farm_description(FD, &farm))
	{
		return (OK);
	}
	printf("ERROR\n");
	return (KO);
}
