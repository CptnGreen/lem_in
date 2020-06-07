/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:15 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define ER_R1 "parse_rooms(): Reached EOF, but no links found.\n"
#define ER_R2 "check_coordinates(): Letter as the coordinate.\n"
#define ER_R3 "parse_rooms(): No rooms' declarations - empty map.\n"
#define ER_R4 "check_first_symb(): Bad line (starts with 'L' or empty).\n"
#define ER_R5 "handle_new_room(): Duplicate.\n"
#define ER_R6 "check_first_symb(): Start/end command not followed by room.\n"

#define IS_HASH 3
#define NO_HASH 4
#define COMMENT 5

/*
** Checks if there is a letter instead of a digit
** in a room's coordinate field
**
** Signed coordinates are nor allowed,
** coordinates starting with zeroes are allowed.
*/

int			check_coordinates(t_farm *farm, char **split)
{
	int				i;
	int				n;

	n = 0;
	while (++n != 3)
	{
		i = -1;
		while (split[n][++i])
		{
			if (split[n][i] < '0' || split[n][i] > '9')
			{
				wipe_mstr(split);
				ft_putstr_fd(ER_R2, farm->log_fd);
				return (KO);
			}
		}
	}
	return (OK);
}

void		process_start_end_or_create_dupl(\
						t_farm *farm, t_room *r, int is_hash)
{
	char			*dupl_name;

	if (is_hash == STA_HDR)
	{
		farm->start_counter += 1;
		r->is_start = 1;
		farm->start_room = r;
		return ;
	}
	else if (is_hash == END_HDR)
	{
		farm->end_counter += 1;
		r->is_end = 1;
		farm->end_room = r;
		return ;
	}
	dupl_name = ft_strjoin(r->name, "'");
	init_and_append_room(farm, dupl_name, r->x, r->y);
	ft_strdel(&dupl_name);
}

/*
** For every room (except start and end) this function
** also creates (and attaches to it in farm's rooms' list)
** duplicate which will be used later for discovering
** best paths.
*/

int			handle_new_room(t_farm *farm, char **split, int *is_hash)
{
	t_room			*r;
	int				x;
	int				y;

	if (check_coordinates(farm, split) == KO)
		return (KO);
	x = ft_atoi(split[1]);
	y = ft_atoi(split[2]);
	if ((r = init_and_append_room(farm, split[0], x, y)))
	{
		if (r->is_dupl)
		{
			wipe_mstr(split);
			ft_putstr_fd(ER_R5, farm->log_fd);
			return (KO);
		}
		process_start_end_or_create_dupl(farm, r, *is_hash);
		if (r->is_start || r->is_end)
			*is_hash = 0;
		wipe_mstr(split);
		return (OK);
	}
	wipe_mstr(split);
	return (KO);
}

/*
** - only two directives are treated as such - ##start and ##end,
** anything else starting with a hash is treated as a comment;
**
** - comments between directive and special room declaration
** are allowed;
**
** - directive without following room declaration is forbidden.
*/

int			check_first_symb(t_farm *farm, t_input_line **input, int *is_hash)
{
	char	*line;

	line = (*input)->line;
	if (line[0] == '\0' || line[0] == 'L')
	{
		ft_putstr_fd(ER_R4, farm->log_fd);
		return (KO);
	}
	if (line[0] == '#')
	{
		if (*is_hash == STA_HDR || *is_hash == END_HDR)
		{
			ft_putstr_fd(ER_R6, farm->log_fd);
			return (KO);
		}
		else if (ft_strequ(line, "##start"))
			*is_hash = STA_HDR;
		else if (ft_strequ(line, "##end"))
			*is_hash = END_HDR;
		else
			*is_hash = COMMENT;
		(*input) = (*input)->next;
		return (IS_HASH);
	}
	return (NO_HASH);
}

/*
** Called [from main() ->] process_input() -> parse_input()
** after parse_n_ants()
*/

int			parse_rooms(t_farm *f, t_input_line **input)
{
	char		**spl;
	int			is_hash;
	int			res;

	if (*input)
	{
		is_hash = 0;
		while (*input)
		{
			if ((res = check_first_symb(f, input, &is_hash)) == KO)
				return (KO);
			else if (res == IS_HASH)
				continue ;
			spl = ft_strsplit((*input)->line, ' ');
			if (!spl[0] || !spl[1] || !spl[2] || spl[3])
				return ((hndl_end_of_rooms(f, spl, &is_hash) == OK) ? OK : KO);
			if ((handle_new_room(f, spl, &is_hash)) == KO)
				return (KO);
			(*input) = (*input)->next;
		}
		ft_putstr_fd(ER_R1, f->log_fd);
	}
	ft_putstr_fd(ER_R3, f->log_fd);
	return (KO);
}
