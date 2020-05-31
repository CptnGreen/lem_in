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
# define LOG "stderr.log"

# define OK 1
# define KO 0

# define ROOM_MISSING -2
# define HEADERS_TOO_MANY -1

# define FOUND_START 1
# define FOUND_END 2
# define COMMENT_FOUND 3

# define FOUND_PATH 1
# define NO_MORE_PATHS_FOUND 2

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
	struct s_room		*room;
}						t_ant;

typedef struct			s_room{
	int					num;
	char				*name;
	int					n_ants;
	struct s_ant_queue	*ants;
	int					x;
	int					y;
	char				is_start;
	char				is_end;
	struct s_room		*next;
	int					d;
	struct s_room		*parent;
}						t_room;

typedef struct			s_ant_queue{
	t_ant				*ant;
	struct s_ant_queue	*next;
}						t_ant_queue;

typedef struct			s_room_queue{
	t_room				*room;
	struct s_room_queue	*next;
	int					ants_on_path;
	struct s_ant_queue	*ants;
}						t_room_queue;

typedef struct			s_path
{
	int					n_ants_inside;
	t_room				*gateway_room;
	struct s_ant_queue	*ants;
	struct s_path		*next;
	int					is_sorted;
}						t_path;

typedef struct			s_link{
	char				*src;
	char				*dst;
	struct s_link		*next;
}						t_link;

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
** Input processing:
*/

int						init_farm(t_farm *farm);
int						get_input(\
							t_farm *farm, int fd, t_input_line **input_lst);
int						process_farm_description(\
							t_input_line **input, t_farm *farm);
int						redistribute_ants(t_farm *farm);

int						parse_n_ants(t_farm *farm, t_input_line **input);
int						parse_rooms(t_farm *farm, t_input_line **input_passed);
int						handle_no_more_rooms(\
							t_farm *farm, char **split, char **line);
int						parse_links(t_farm *farm, t_input_line **input);

int						handle_start_and_end_headers(t_farm *farm, char **line);

int						find_next_path(t_farm *farm);
void					rebuild_paths(t_farm *farm);
int						reset_queue(t_room_queue **q);
void					reset_rooms(t_farm *farm);

/*
** Utils:
*/


int						make_ants(t_farm *farm);
t_room					*append_room(t_room **where, t_room *what);
t_room					*init_and_append_room(\
							t_farm *farm, char const *name, int x, int y);
t_ant					*init_and_append_ant(t_farm *farm, int num);
t_path					*init_and_append_path(\
							t_farm *farm, t_room *gateway_room);
int						enqueue_room(t_room_queue **queue, t_room *room);
int						enqueue_ant(t_ant_queue **queue, t_ant *ant);
t_ant					*dequeue_ant(t_ant_queue **queue);

void					wipe_farm(t_farm *farm);
void					wipe_paths(t_path **path);
void					wipe_input(t_input_line **input_passed);
void					wipe_ants_queue(t_ant_queue **ants);

int						lem_in(t_farm *farm);

/*
** Debugging:
*/

void					print_room_v(t_room *room);
int						print_rooms_v(t_room *rooms);
int						print_rooms_queue_v(t_room_queue *queue);
int						print_paths(t_path *paths);
void					print_ants(t_room *room);

#endif
