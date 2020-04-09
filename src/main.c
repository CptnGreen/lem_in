#include "lem-in.h"

int			make_ants(t_farm *farm)
{
	int		i;
	t_ant	*a;

	i = 0;
	while (i < farm->n_ants)
	{
		init_and_append_ant(farm, i + 1);
		i += 1;
	}
	a = farm->ants;
	while (a)
	{
		enqueue_ant(&(farm->start_room->ants), a);
		a = a->next;
	}
	return (OK);
}

int			process_farm_description(t_input_line *input, t_farm *farm)
{
	char	*line;
	int		i;

	line = NULL;
    if (get_n_ants(farm, input, &line) != OK || \
		get_rooms(farm, input->next, &line) != OK) // ||	 \
		/* get_links(farm, fd, &line) != OK) */
		return (KO);
	printf("%s\n", input->line);
	i = 0;
	while (assign_depth(farm) != NO_MORE_PATHS_FOUND)
		i += 1;
	if (i == 0)
		return (KO);
	make_ants(farm);
	ft_putstr_fd("Farm description successfully processed.\n", farm->log_fd);
	return (OK);
}

int		get_input(t_farm *farm, int fd, t_input_line **input_lst)
{
	t_input_line	*prev;
	t_input_line	*cur;
	char			*line;
	int				is_first;

	cur = NULL;
	line = NULL;
	is_first = 1;
	while (get_next_line(fd, &line) > 0)
	{
		prev = cur;
		if (!(cur = (t_input_line *)ft_memalloc(sizeof(t_input_line))))
			return (KO);
		if (is_first)
		{
			*input_lst = cur;
			is_first = 0;
		}
		if (prev)
			prev->next = cur;
		cur->line = ft_strdup(line);
		ft_strdel(&line);
		cur->next = NULL;
	}
	if (cur)
	{
		ft_putstr_fd("Input lines parsed to list.\n", farm->log_fd);
		return (OK);
	}
	ft_putstr_fd("Input empty; Aborting.\n", farm->log_fd);
	return (KO);
}

void	print_input(t_input_line *input_seed)
{
	t_input_line	*input;

	input = input_seed;
	while (input)
	{
		printf("%s\n", input->line);
		input = input->next;
	}
}

int		main(void)
{
	t_farm			farm;
	t_input_line	*input;

	if (init_farm(&farm) &&	\
		get_input(&farm, FD, &input) && \
		process_farm_description(input, &farm))
	{
		print_input(input);
		/* print_farm_description(&farm); */
		/* print_farm_description_v(&farm); */
		/* lem_in(&farm); */
		return (OK);
	}
	printf("ERROR\n");
	return (KO);
}
