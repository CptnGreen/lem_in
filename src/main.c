#include "lem-in.h"

int		main(void)
{
	t_farm	farm;

	init_farm(&farm);
	process_farm_description(FD, &farm);
	return (0);
}
