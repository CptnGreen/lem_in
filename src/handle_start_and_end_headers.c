#include "lem-in.h"

int			get_start_room(int fd, t_farm *farm, char **line)
{
	printf("Successfully found start header!\n"); // remove later!
	farm->start_counter += 1;
	if (get_rooms(fd, farm, line))
	{
		farm->rooms->is_start = 1;
		return (HEADER_IS_FOUND);
	}
	perror("lem_in: Start room declared but not present.\n");
	return (ROOM_MISSING);
}

int			get_end_room(int fd, t_farm *farm, char **line)
{
	printf("Successfully found end header!\n"); // remove later!
	farm->end_counter += 1;
	if (get_rooms(fd, farm, line))
	{
		farm->rooms->is_end = 1;
		return (HEADER_IS_FOUND);
	}
	perror("lem_in: end room declared but not present.\n");
	return (ROOM_MISSING);
}

int			handle_start_header(int fd, t_farm *farm, char **line)
{
	if (ft_strnstr(*line, "##start", ft_strlen("##start")) != 0)
	{
		ft_strdel(line);
		if (farm->start_counter == 0)
		{
			if (get_start_room(fd, farm, line) == ROOM_MISSING)
				return (ROOM_MISSING);
			return (HEADER_IS_FOUND);
		}
		else
		{
			perror("lem-in: Too many start headers. Aborting.\n");
			return (HEADER_TOO_MANY);
		}
	}
	return (HEADER_NOT_FOUND);
}

int			handle_end_header(int fd, t_farm *farm, char **line)
{
	if (ft_strnstr(*line, "##end", ft_strlen("##end")) != 0)
	{
		ft_strdel(line);
		if (farm->end_counter == 0)
		{
			if (get_end_room(fd, farm, line) == ROOM_MISSING)
				return (ROOM_MISSING);
			return (HEADER_IS_FOUND);
		}
		else
		{
			perror("lem-in: Too many end headers. Aborting.\n");
			return (HEADER_TOO_MANY);
		}
	}
	return (HEADER_NOT_FOUND);
}

int			handle_start_and_end_headers(int fd, t_farm *farm, char **line)
{
	int		res_start;
	int		res_end;

	res_start = handle_start_header(fd, farm, line);
	if (res_start != HEADER_NOT_FOUND)
		return (res_start);
	res_end = handle_end_header(fd, farm, line);
	if (res_end != HEADER_NOT_FOUND)
		return (res_end);
	return (HEADER_NOT_FOUND);
}
