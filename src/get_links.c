#include "lem-in.h"

int		get_new_link(int fd, t_farm *farm, char **line)
{
	char		**split;
	int			i;

	while ((*line)[0] == '#')
	{
		ft_strdel(line);
		if (!(get_next_line(fd, line) > 0))
		{
			printf("Reached end of the input. Last line is a comment.\n");
			return (OK);
		}
	}
	split = ft_strsplit(*line, '-');
	ft_strdel(line);
	i = 0;
	while (split[i])
		i += 1;
	if (i != 2)
	{
		wipe_mstr(split);
		perror("lem-in: Wrong link declaration found; Aborting.\n");
		return (KO);
	}
	while (farm->links)
		(farm->links) = (farm->links)->next;
	(farm->links) = init_link(split[0], split[1]);
	wipe_mstr(split);
	printf("New link: source = \"%s\", destination = \"%s\"\n", \
		   (farm->links)->src, (farm->links)->dst);
	return (OK);
}

int		get_links(int fd, t_farm *farm, char **line)
{
	if (get_new_link(fd, farm, line) == KO)
		return (KO);
	while (get_next_line(fd, line) > 0)
	{
		if (get_new_link(fd, farm, line) == KO)
			return (KO);
	}
	printf("Successfully reached end of the input.\n");
	return (OK);
}
