#include "lem-in.h"

void	print_input(t_input_line *input_seed)
{
	t_input_line	*input;

	input = input_seed;
	while (input)
	{
		printf("%s\n", input->line);
		input = input->next;
	}
	printf("\n");
	return ;
}

int		main(void)
{
	t_farm			farm;
	t_input_line	*input;

	if (init_farm(&farm) &&	\
		get_input(&farm, FD, &input))
	{
		print_input(input);
		if (process_farm_description(&input, &farm) && \
			lem_in(&farm))
		{
			sleep(3);
			return (0);
		}
	}
	printf("ERROR\n");
	sleep(3);
	return (1);
}
