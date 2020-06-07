# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 03:09:01 by slisandr          #+#    #+#              #
#    Updated: 2020/05/25 03:09:03 by slisandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re ft_printf norm memcheck test check_all

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS =

NAME = lem-in

MAP = ant_farm.txt
LOG = lem_in.log
LEAKS = valgrind-out.txt

SRC_DIR = src
SRC_RAW = \
	process_input.c \
	store_neighbours_in_rooms.c \
	set_the_stage.c \
	init_farm.c \
	wipe_farm.c \
	wipe_paths.c \
	wipe_input.c \
	wipe_ants_queue.c \
	get_input.c \
	redistribute_ants.c \
	parse_n_ants.c \
	append_room.c \
	init_and_append_room.c \
	init_and_append_ant.c \
	init_and_append_path.c \
	parse_rooms.c \
	hndl_end_of_rooms.c \
	parse_links.c \
	check_link.c \
	print_room_v.c \
	print_paths.c \
	print_ants.c \
	print_rooms_v.c \
	print_rooms_queue_v.c \
	print_flow_matrix.c \
	enqueue_room.c \
	enqueue_ant.c \
	dequeue_ant.c \
	rebuild_paths.c \
	wipe_rooms_queue.c \
	destroy_room.c \
	find_shortest_path.c \
	lem_in.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))

MAIN_RAW = main.c
MAIN = $(addprefix $(SRC_DIR)/,$(MAIN_RAW))

OBJ_DIR = obj
OBJ_RAW = $(SRC_RAW:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_RAW))

all: $(NAME)

$(NAME): ft_printf $(OBJ)
	@ $(CC) $(LFLAGS) -o $(NAME) $(OBJ) $(MAIN) -I "includes/" -I "ft_printf/includes/" -I "ft_printf/libft/includes" -L "ft_printf/" -lftprintf
ft_printf:
	@ make -C ft_printf/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@ $(CC) $(CFLAGS) -I "includes/" -I "ft_printf/includes/" -I "ft_printf/libft/includes" -c $< -o $@
$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)

clean:
	@ rm -rf $(OBJ_DIR) $(LOG) $(LEAKS)*
	@ make clean -C ft_printf/
fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C ft_printf/

re: fclean all

norm:
	@ make norm -C ft_printf/
	@ make norm -C ft_printf/libft/
	@ norminette $(SRC_DIR) includes

memcheck: all
	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(LEAKS) ./$(NAME) < maps/$(MAP)

test: all
	@ echo "" | > $(LOG)
	@ echo -e "\nOUTPUT:\n================\n"
	@ ./$(NAME) < maps/$(MAP)
	@ echo -e "\n================\n"

check_all: all
	@ bash check_all.sh
