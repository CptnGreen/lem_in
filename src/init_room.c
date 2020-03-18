#include "lem-in.h"

t_room		*init_room(int num, char const *str, int x, int y)
{
	t_room	*room;

	room = NULL;
	if ((room = (t_room *)ft_memalloc(sizeof(t_room))))
	{
		room->num = num;
		room->name = ((str) ? (ft_strdup(str)) : (NULL));
		room->x = x;
		room->y = y;
		room->ant_num = 0;
		room->next = NULL;
		room->depth = -1;
		room->is_start = 0;
		room->is_end = 0;
	}
	else
		perror("lem_in: Failed to allocate memory for a new room.\n");
	return (room);
}
