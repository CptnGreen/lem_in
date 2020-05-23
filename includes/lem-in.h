#ifndef LEM_IN_H
# define LEM_IN_H

# define FD 0
# define LOG "stderr.log"

#define OK 1
#define KO 0

#define ROOM_MISSING -2
#define HEADERS_TOO_MANY -1
#define COMMENT_FOUND 0
#define START_HEADER_IS_FOUND 1
#define END_HEADER_IS_FOUND 2

#define FOUND_PATH 1
#define NO_MORE_PATHS_FOUND 2


# include "libft.h"

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
	int					depth;
	struct s_room		*parent;
	char				is_chosen;
}						t_room;

typedef struct			s_ant_queue{
	t_ant				*ant;
	struct s_ant_queue	*next;
}						t_ant_queue;

typedef struct			s_room_queue{
	t_room				*room;
	struct s_room_queue	*next;
}						t_room_queue;

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
	struct s_link		*links;
	int					n_ants;
	int					n_rooms;
	char				start_counter;
	char				end_counter;
	char				**adj_matrix;
	struct s_room_queue	*gateways;
}						t_farm;

/*
** Input processing:
*/

int						init_farm(t_farm *farm);
int						get_input(t_farm *farm, int fd, t_input_line **input_lst);
int						process_farm_description(t_input_line *input, t_farm *farm);
t_link					*init_link(t_farm *farm, char const *src, char const *dst);
int						parse_n_ants(t_farm *farm, t_input_line *input, char **line);
int						parse_rooms(t_farm *farm, t_input_line **input_passed, char **line);
int						handle_start_and_end_headers(t_farm *farm, char **line);
int						parse_links(t_farm *farm, t_input_line *input);
void					print_farm_description(t_farm *farm);
void					print_farm_description_v(t_farm *farm);

int						assign_depth(t_farm *farm);
int						choose_path(t_farm *farm);
int						reset_depth(t_room_queue **q);

/*
** Utils:
*/

t_room					*append_room(t_room **where, t_room *what);
t_room					*init_and_append_room(t_farm *farm, char const *name, int x, int y);
t_ant					*init_and_append_ant(t_farm *farm, int num);
int						enqueue_room(t_room_queue **queue, t_room *room);
int						enqueue_ant(t_ant_queue **queue, t_ant *ant);
t_ant					*dequeue_ant(t_ant_queue **queue);

int						lem_in(t_farm *farm);

/*
** Debugging:
*/

int						print_links(t_link *links);
void					print_room_v(t_room *room);
int						print_rooms_v(t_room *rooms);
int						print_rooms_queue_v(t_room_queue *queue);

#endif
