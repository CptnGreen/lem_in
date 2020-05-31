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

.PHONY: all clean fclean re ft_printf norm memcheck test

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS =

NAME = lem-in
# MAP = maps_examples/valid/big/map_big_1
MAP = my_map5
# MAP = my_map1
# MAP = three_ways
LOG = stderr.log

SRC_DIR = src
SRC_RAW = \
	init_farm.c \
	wipe_farm.c \
	wipe_paths.c \
	wipe_input.c \
	wipe_ants_queue.c \
	get_input.c \
	redistribute_ants.c \
	process_farm_description.c \
	handle_start_and_end_headers.c \
	parse_n_ants.c \
	append_room.c \
	init_and_append_room.c \
	init_and_append_ant.c \
	init_and_append_path.c \
	parse_rooms.c \
	handle_no_more_rooms.c \
	parse_links.c \
	print_room_v.c \
	print_paths.c \
	print_ants.c \
	print_rooms_v.c \
	print_rooms_queue_v.c \
	enqueue_room.c \
	enqueue_ant.c \
	make_ants.c \
	dequeue_ant.c \
	rebuild_paths.c \
	reset_queue.c \
	reset_rooms.c \
	find_next_path.c \
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
	@ rm -rf $(OBJ_DIR)
	@ make clean -C ft_printf/
fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C ft_printf/

re: fclean all

norm:
	@ norminette $(SRC_DIR) includes

memcheck: all
	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) < $(MAP)

test: all
	@ echo "" | > $(LOG)
	@ echo -e "\nOUTPUT:\n================\n"
	@ ./$(NAME) < $(MAP)
	@ echo -e "\n================\n"

emilwallner: all
	@ echo "" > stderr.log
	@ sh Maps/run.sh

Xel4ek: all
	@ echo "" > stderr.log
	@ ./check.sh
