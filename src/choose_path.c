#include "lem-in.h"

int		choose_path(t_farm *farm)
{
	t_room	*r;

	r = farm->end_room;
	if (r->parent)
	{
		/* printf("Last chosen path:\n"); */
		/* printf("==#|=name==============|============parent=|=x==|=y==|==d=|=flags=|\n"); */
		/* print_room(r); */
		r = r->parent;
		enqueue_room(&(farm->gateways), r);
		while (!(r->is_start))
		{
			r->is_chosen = 1;
			/* print_room(r); */
			r = r->parent;
		}
		/* print_room(r); */
		/* printf("===|===================|===================|====|====|====|=======|\n"); */
		return (FOUND_PATH);
	}
	return (NO_MORE_PATHS_FOUND);
}
