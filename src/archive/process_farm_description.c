#include "lem-in.h"

int			process_farm_description(int fd, t_farm *farm)
{
	char	*line;

	line = NULL;
    if (get_n_ants(fd, farm, &line) != OK || \
		get_rooms(fd, farm, &line) != OK || \
		get_links(fd, farm, &line) != OK)
		return (KO);
	while (assign_depth(farm) != NO_MORE_PATHS_FOUND)
		;
	printf("Gateways - last rooms (except for \"end\") in the found paths:\n");
	print_rooms(farm->gateways);
	printf("Farm description successfully processed.\n\n");
	return (OK);
}
