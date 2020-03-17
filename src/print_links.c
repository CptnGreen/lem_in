#include "lem-in.h"

int		print_links(t_link *links)
{
	t_link		*link;
	int			i;

	printf("==========================\n");
	if (links)
	{
		i = 0;
		link = links;
		while (link)
		{
			printf("%3d: \"%s\" ---> \"%s\"\n", i, link->src, link->dst);
			link = link->next;
			i += 1;
		}
		printf("==========================\n");
		return (OK);
	}
	perror("lem-in: Couldn't print links 'cause passed argument is NULL.\n");
	printf("==========================\n");
	return (KO);
}
