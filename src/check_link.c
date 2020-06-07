/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:10 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:11 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define ER_L2 "check_link(): Bad link - loop.\n"
#define ER_L6 "check_link(): Bad link - missing room.\n"

/*
** Flow matrix notation:
**
** - no connection: ' ' (space)
** - real connection, zero flow (0 / 1): '*'
** - real connection, saturated (1 / 1): '+'
** - virt. connection, flow in the opposite direction is zero (0 / 0): 'x'
** - virt. connection, flow in the opposite direction is saturated (-1 / 0): '-'
*/

void		update_start_end_flow(t_farm *farm, t_room *r_src, t_room *r_dst)
{
	if (r_src->is_start)
	{
		farm->flow_matrix[r_src->num][r_dst->num] = '*';
		farm->flow_matrix[r_dst->num][r_src->num] = 'x';
	}
	if (r_dst->is_start)
	{
		farm->flow_matrix[r_dst->num][r_src->num] = '*';
		farm->flow_matrix[r_src->num][r_dst->num] = 'x';
	}
	if (r_src->is_end)
	{
		farm->flow_matrix[r_dst->num + 1][r_src->num] = '*';
		farm->flow_matrix[r_src->num][r_dst->num + 1] = 'x';
	}
	if (r_dst->is_end)
	{
		farm->flow_matrix[r_src->num + 1][r_dst->num] = '*';
		farm->flow_matrix[r_dst->num][r_src->num + 1] = 'x';
	}
}

/*
** It also tracks start and end rooms in links in order
** to shoot error if there is no connection to at least one of them.
*/

void		initialize_flow(t_farm *farm, t_room *r_src, t_room *r_dst)
{
	if (r_src->is_start || r_dst->is_start || r_src->is_end || r_dst->is_end)
	{
		if (r_src->is_start || r_dst->is_start)
			farm->start_counter += 1;
		if (r_src->is_end || r_dst->is_end)
			farm->end_counter += 1;
		update_start_end_flow(farm, r_src, r_dst);
	}
	else
	{
		farm->flow_matrix[r_src->num + 1][r_dst->num] = '*';
		farm->flow_matrix[r_dst->num][r_src->num + 1] = 'x';
		farm->flow_matrix[r_dst->num + 1][r_src->num] = '*';
		farm->flow_matrix[r_src->num][r_dst->num + 1] = 'x';
	}
}

/*
** Called in parse_next_link()
**
** Checks for:
** (1) loop-links (like "room-room"),
** (2) links pointing to missing rooms.
**
** Duplicate links are NOT treated as errors!
*/

int			check_link(t_farm *farm, char const *src, char const *dst)
{
	t_room	*r;
	t_room	*r_src;
	t_room	*r_dst;

	if (ft_strequ(src, dst))
	{
		ft_putstr_fd(ER_L2, farm->log_fd);
		return (KO);
	}
	r_src = NULL;
	r_dst = NULL;
	r = farm->rooms;
	while (r)
	{
		r_src = ((!r_src && ft_strequ(src, r->name)) ? r : r_src);
		r_dst = ((!r_dst && ft_strequ(dst, r->name)) ? r : r_dst);
		if (r_src && r_dst)
		{
			initialize_flow(farm, r_src, r_dst);
			return (OK);
		}
		r = r->next;
	}
	ft_putstr_fd(ER_L6, farm->log_fd);
	return (KO);
}
