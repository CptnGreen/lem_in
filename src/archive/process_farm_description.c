#include "lem-in.h"

int			process_farm_description(int fd, t_farm *farm)
{
	char	*line;

	line = NULL;
    if (parse_n_ants(fd, farm, &line) != OK || \
		parse_rooms(fd, farm, &line) != OK || \
		parse_links(fd, farm, &line) != OK)
		return (KO);
	while (find_path(farm) != NO_MORE_PATHS_FOUND)
		;
	printf("Gateways - last rooms (except for \"end\") in the found paths:\n");
	print_rooms_v(farm->gateways);
	printf("Farm description successfully processed.\n\n");
	return (OK);
}
