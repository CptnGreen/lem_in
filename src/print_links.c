#include "lem-in.h"

int		print_links(t_link *links)
{
	t_link		*link;
	int			i;

	if (links)
	{
		i = 0;
		link = links;
		while (link)
		{
			printf("%s-%s\n", link->src, link->dst);
			link = link->next;
			i += 1;
		}
		return (OK);
	}
	perror("lem-in: Couldn't print links 'cause passed argument is NULL.\n");
	return (KO);
}
