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

.PHONY: all clean fclean re libft norm memcheck test unit-tests

CC = clang
CFLAGS = -Wall -Werror -Wextra
LFLAGS =

NAME = lem-in
MAP = three_ways
LOG = stderr.log

SRC_DIR = src
SRC_RAW = \
	init_farm.c \
	get_input.c \
	process_farm_description.c \
	init_link.c \
	handle_start_and_end_headers.c \
	parse_n_ants.c \
	append_room.c \
	init_and_append_room.c \
	init_and_append_ant.c \
	parse_rooms.c \
	parse_links.c \
	print_links.c \
	print_farm_description_v.c \
	print_room_v.c \
	print_rooms_v.c \
	print_rooms_queue_v.c \
	enqueue_room.c \
	enqueue_ant.c \
	dequeue_ant.c \
	choose_path.c \
	reset_depth.c \
	find_path.c \
	lem_in.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))

MAIN_RAW = main.c
MAIN = $(addprefix $(SRC_DIR)/,$(MAIN_RAW))

OBJ_DIR = obj
OBJ_RAW = $(SRC_RAW:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_RAW))

all: $(NAME)

$(NAME): libft $(OBJ)
	@ $(CC) $(LFLAGS) -o $(NAME) $(OBJ) $(MAIN) -I "includes/" -I "libft/includes/" -L "libft/" -lft
libft:
	@ make -C libft/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@ $(CC) $(CFLAGS) -I "includes/" -I "libft/includes/" -c $< -o $@
$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)

clean:
	@ rm -rf $(OBJ_DIR)
	@ make clean -C libft/
fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C libft/

re: fclean all

norm:
	@ norminette $(SRC_DIR) includes

memcheck:
	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME)

test: all
	@ echo "" | > $(LOG)
	@ echo -e "\nOUTPUT:\n================\n"
	@ ./$(NAME) < $(MAP)
	@ echo -e "\n================\n"

unit-tests:
	@ cd /home/ak/Documents/lem_in_test && sh unit_tests.sh && cd /home/ak/Documents/lem_in

emilwallner: all
	@ echo "" > stderr.log
	@ sh Maps/run.sh
