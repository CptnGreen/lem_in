#include "lem-in.h"

void	print_farm_description_v(t_farm *farm)
{
	/* printf("%d ants found.\n", farm->n_ants); */
	/* print_rooms_v(farm->rooms); */
	printf("Gateways - last rooms (except for \"end\") in the found paths:\n");
	print_rooms_queue_v(farm->gateways);
	printf("\n");
}
