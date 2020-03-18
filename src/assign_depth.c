#include "lem-in.h"

int		assign_depth(t_farm *farm, int d)
{
	t_room		*room;
	int			i;

	if (d == 0)
	{
		room = farm->room_ar[0];
		while (!(room->is_start))
			room = room->next;
		room->depth = 0;
		d = 1;
	}
	room = farm->room_ar[0];
	while (!(room->depth == d - 1))
		room = room->next;
	i = 0;
	while (farm->adj_matrix[room->num][i])
	{
		if (farm->adj_matrix[room->num][i] == '1' && farm->room_ar[i]->depth == -1)
			farm->room_ar[i]->depth = d;
		i += 1;
	}
	print_rooms(farm->rooms);
	if (room->is_end == 1)
		assign_depth(farm, d + 1);






	return (OK);
}
