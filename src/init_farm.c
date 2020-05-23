#include "lem-in.h"

int		init_farm(t_farm *farm)
{
	if (farm && \
		(farm->log_fd = open(LOG, O_WRONLY | O_APPEND)) >= 0)
	{
		farm->n_ants = 0;
		farm->rooms = NULL;
		farm->start_room = NULL;
		farm->end_room = NULL;
		farm->links = NULL;
		farm->gateways = NULL;
		farm->ants = NULL;
		farm->n_rooms = 0;
		farm->start_counter = 0;
		farm->end_counter = 0;
		farm->adj_matrix = NULL;
		farm->room_ar = NULL;
		ft_putstr_fd("init_farm(): Success.\n", farm->log_fd);
		return (OK);
	}
	return (KO);
}
