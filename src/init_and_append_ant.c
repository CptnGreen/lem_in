#include "lem-in.h"

t_ant		*init_ant(t_farm *farm, int num)
{
	t_ant	*ant;

	ant = NULL;
	if ((ant = (t_ant *)ft_memalloc(sizeof(t_ant))))
	{
		ant->num = num;
		ant->room = NULL;
		ant->next = NULL;
	}
	else
		ft_putstr_fd("Failed to allocate memory for an ant.\n", farm->log_fd);
	return (ant);
}

t_ant		*init_and_append_ant(t_farm *farm, int num)
{
	t_ant		*ant;
	t_ant		*prev;

	prev = farm->ants;
	ant = farm->ants;
	while (ant)
	{
		prev = ant;
		ant = ant->next;
	}
	ant = init_ant(farm, num);
	if (farm->ants)
		prev->next = ant;
	else
		farm->ants = ant;
	return (ant);
}
