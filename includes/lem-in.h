#ifndef LEM_IN_H
# define LEM_IN_H

# define FD 0

#define OK 1
#define KO 0

#define ROOM_MISSING -2

#define HEADER_IS_FOUND 1
#define HEADER_NOT_FOUND 0
#define HEADER_TOO_MANY -1

# include "libft.h"

/*
** for perror() and strerror():
*/

# include <stdio.h>

typedef struct			s_ant{
	int					num;
}						t_ant;

typedef struct			s_room{
	int					num;
	char				*name;
	int					ant_num;
	int					x;
	int					y;
	char				is_start;
	char				is_end;
	struct s_room		*next;
	int					depth;
	struct s_room		*parent;
	char				is_chosen;
}						t_room;

/*
** c - capacity, f - flow
*/

typedef struct			s_link{
	char				*src;
	char				*dst;
	int					c;
	int					f;
	struct s_link		*next;
}						t_link;

typedef struct			s_farm{
	t_ant				*ants;
	t_room				*rooms;
	t_room				**room_ar;
	t_link				*links;
	int					n_ants;
	int					n_rooms;
	char				start_counter;
	char				end_counter;
	char				**adj_matrix;
}						t_farm;

/*
** Input processing:
*/

int						init_farm(t_farm *farm);
t_room					*init_room(int num, char const *str, int x, int y);
t_link					*init_link(char const *src, char const *dst);
int						process_farm_description(int fd, t_farm *farm);
int						get_n_ants(int fd, t_farm *farm, char **line);
int						get_rooms(int fd, t_farm *farm, char **line);
int						handle_start_and_end_headers(int fd, t_farm *farm, char **line);
int						get_links(int fd, t_farm *farm, char **line);

int						assign_depth(t_farm *farm, int d);

/*
** Common utils:
*/

int						append_room(t_farm *farm, char const *name, int x, int y);

/*
** Debugging:
*/

int						print_rooms(t_room *rooms);
int						print_links(t_link *links);

#endif
