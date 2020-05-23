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
	return ;
}

int		main(void)
{
	t_farm			farm;
	t_input_line	*input;

	if (init_farm(&farm) &&	\
		get_input(&farm, FD, &input)) // &&
	{
		print_input(input);
		if (process_farm_description(input, &farm)
			/* print_farm_description(&farm); */
			/* print_farm_description_v(&farm); */
			/* lem_in(&farm); */)
			return (0); // SUCCESS
	}
	printf("main(): ERROR\n");
	return (1); // FAIL
}
