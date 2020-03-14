#ifndef LEM_IN_H
# define LEM_IN_H

# define FD 0

# include "libft.h"

/*
** for perror() and strerror():
*/

# include <stdio.h>

typedef struct			s_ant{
	int					num;
}						t_ant;

typedef struct			s_room{
	char				*name;
	char				is_start;
	char				is_end;
	int					ant_num;
	int					x;
	int					y;
	struct s_room		*next;
}						t_room;

/*
** c - capacity, f - flow
*/

typedef struct			s_tube{
	t_room				*src;
	t_room				*dst;
	int					c;
	int					f;
}						t_tube;

typedef struct			s_farm{
	t_ant				*ants;
	t_room				*rooms;
	int					n_ants;
	int					n_rooms;
}						t_farm;

int						process_farm_description(int fd, t_farm *farm);
t_room					*init_room(char const *str, int x, int y);
void					init_farm(t_farm *farm);
int						get_room_description(int fd, t_farm *farm);

#endif
