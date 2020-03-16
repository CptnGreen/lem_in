#include "lem-in.h"

int		main(void)
{
	t_farm	farm;

	/* freopen("stderr.log", "w", stderr); */
	if (init_farm(&farm) && \
		process_farm_description(FD, &farm))
		return (OK);
	printf("ERROR\n");
	return (KO);
}
