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
		room->n_ants = 0;
		room->next = NULL;
		room->ants = NULL;
		room->depth = -1;
		room->is_start = 0;
		room->is_end = 0;
	}
	else
		perror("lem_in: Failed to allocate memory for a new room.\n");
	return (room);
}

t_room		*init_and_append_room(t_farm *farm, char const *name, int x, int y)
{
	t_room		*room;
	t_room		*prev;

	prev = farm->rooms;
	room = farm->rooms;
	while (room)
	{
		prev = room;
		room = room->next;
	}
	room = init_room((farm->n_rooms)++, name, x, y);
	if (farm->rooms)
		prev->next = room;
	else
		farm->rooms = room;
	return (room);
}
