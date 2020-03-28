#include "lem-in.h"

int			handle_start_header(t_farm *farm, char **line)
{
	if (ft_strnstr(*line, "##start", ft_strlen("##start")) != 0)
	{
		ft_strdel(line);
		if (farm->start_counter == 0)
		{
			farm->start_counter += 1;
			return (START_HEADER_IS_FOUND);
		}
		else
		{
			ft_putstr_fd("Too many start headers. Aborting.\n", farm->log_fd);
			return (HEADERS_TOO_MANY);
		}
	}
	return (COMMENT_FOUND);
}

int			handle_end_header(t_farm *farm, char **line)
{
	if (ft_strnstr(*line, "##end", ft_strlen("##end")) != 0)
	{
		ft_strdel(line);
		if (farm->end_counter == 0)
		{
			farm->end_counter += 1;
			return (END_HEADER_IS_FOUND);
		}
		else
		{
			ft_putstr_fd("Too many end headers. Aborting.\n", farm->log_fd);
			return (HEADERS_TOO_MANY);
		}
	}
	return (COMMENT_FOUND);
}

int			handle_start_and_end_headers(t_farm *farm, char **line)
{
	int		res;

	if ((res = handle_start_header(farm, line)) != COMMENT_FOUND || \
		(res = handle_end_header(farm, line)) != COMMENT_FOUND)
		return (res);
	return (COMMENT_FOUND);
}
