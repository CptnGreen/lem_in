#include "lem-in.h"

int		dequeue_rooms_with_depth(t_room_queue **queue, int d)
{
	while((*queue)->room->depth == d)
		dequeue_room(queue);
	return (OK);
}

int		choose_path(t_farm *farm)
{
	t_room	*r;

	r = farm->end_room;
	if (r->parent)
	{
		printf("Last chosen path:\n");
		printf("==#|=name==============|============parent=|=x==|=y==|==d=|=flags=|\n");
		print_room(r);
		r = r->parent;
		while (!(r->is_start))
		{
			r->is_chosen = 1;
			print_room(r);
			r = r->parent;
		}
		print_room(r);
		printf("===|===================|===================|====|====|====|=======|\n");
		return (FOUND_PATH);
	}
	return (NO_MORE_PATHS_FOUND);
}
