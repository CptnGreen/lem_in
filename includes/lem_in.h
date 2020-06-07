/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:52 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:53 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define FD 0
# define LOG "lem_in.log"

# define OK 1
# define KO 0

# define ROOM_MISSING -2
# define HEADERS_TOO_MANY -1

# define STA_HDR 10
# define END_HDR 11

# define FOUND_PATH 1
# define NO_MORE_PATHS_FOUND 2
# define ENOUGH_PATHS 3

# include "libftprintf.h"

/*
** for perror() and strerror():
*/

# include <stdio.h>

typedef struct			s_input_line{
	struct s_input_line	*next;
	char				*line;
}						t_input_line;

typedef struct			s_ant{
	int					num;
	struct s_ant		*next;
	int					has_moved;
}						t_ant;

typedef struct			s_room{
	int					num;
	char				*name;
	struct s_ant_queue	*ants;
	int					x;
	int					y;
	char				is_start;
	char				is_end;
	char				is_dupl;
	struct s_room		*next;
	int					d;
	struct s_room		*parent;
	int					*neigh_n_ar;
}						t_room;

typedef struct			s_ant_queue{
	t_ant				*ant;
	struct s_ant_queue	*next;
}						t_ant_queue;

typedef struct			s_room_queue{
	t_room				*room;
	struct s_room_queue	*next;
	struct s_ant_queue	*ants;
}						t_room_queue;

typedef struct			s_path
{
	int					n_ants_inside;
	struct s_room		*gateway_room;
	struct s_ant_queue	*ants;
	struct s_path		*next;
	int					is_sorted;
}						t_path;

typedef struct			s_farm{
	int					log_fd;
	struct s_room		*rooms;
	struct s_ant		*ants;
	struct s_room		*start_room;
	struct s_room		*end_room;
	struct s_room		**room_ar;
	int					n_ants;
	int					n_rooms;
	char				start_counter;
	char				end_counter;
	char				**flow_matrix;
	struct s_path		*paths;
}						t_farm;

/*
** Part 1: Input processing:
*/

int						process_input(t_farm *farm);
int						store_neighbours_in_rooms(t_farm *farm);
int						init_farm(t_farm *farm);
int						get_input(\
							t_farm *farm, int fd, t_input_line **input_lst);
int						parse_n_ants(t_farm *farm, t_input_line **input);
int						parse_rooms(t_farm *farm, t_input_line **input_passed);
int						parse_links(t_farm *farm, t_input_line **input);
int						check_link(\
							t_farm *farm, char const *src, char const *dst);
int						hndl_end_of_rooms(\
							t_farm *farm, char **split, int *is_hash);
void					wipe_input(t_input_line **input_passed);

/*
** Part 2: Set the stage:
*/

int						set_the_stage(t_farm *farm);
int						find_shortest_path(t_farm *farm);
void					rebuild_paths(t_farm *farm);
int						redistribute_ants(t_farm *farm);

/*
** Part 3: Lem-in:
*/

int						lem_in(t_farm *farm);
void					wipe_farm(t_farm *farm);

/*
** Utilities:
*/

t_room					*init_and_append_room(\
							t_farm *farm, char const *name, int x, int y);
t_ant					*init_and_append_ant(t_farm *farm, int num);
t_path					*init_and_append_path(\
							t_farm *farm, t_room *gateway_room);
t_room					*append_room(t_room **where, t_room *what);
int						enqueue_room(t_room_queue **queue, t_room *room);
int						enqueue_ant(t_ant_queue **queue, t_ant *ant);
t_ant					*dequeue_ant(t_ant_queue **queue);
void					wipe_ants_queue(t_ant_queue **ants);
int						wipe_rooms_queue(t_room_queue **q);
void					wipe_paths(t_path **path);
void					destroy_room(t_room *r);

/*
** Debugging:
*/

void					print_room_v(t_room *room);
int						print_rooms_v(t_room *rooms);
int						print_rooms_queue_v(t_room_queue *queue);
void					print_ants(t_room *room);
int						print_paths(t_path *paths);
void					print_flow_matrix(t_farm *f);

#endif
