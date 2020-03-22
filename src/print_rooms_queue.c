#include "lem-in.h"

int		print_rooms_queue(t_room_queue *queue)
{
	t_room_queue	*q;

	if (queue)
	{
		printf("==#|=name==============|============parent=|=x==|=y==|==d=|=flags=|\n");
		q = queue;
		while (q)
		{
			print_room(q->room);
			q = q->next;
		}
		printf("===|===================|===================|====|====|====|=======|\n");
		return (OK);
	}
	perror("lem-in: Couldn't print rooms' queue 'cause passed argument is NULL.\n");
	return (KO);
}
