.PHONY: all clean fclean re libft norm memcheck test

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS =

NAME = lem-in

SRC_DIR = src
SRC_RAW = \
	init_farm.c \
	init_link.c \
	handle_start_and_end_headers.c \
	get_n_ants.c \
	append_room.c \
	init_and_append_room.c \
	init_and_append_ant.c \
	get_rooms.c \
	get_links.c \
	print_farm_description.c \
	print_farm_description_v.c \
	print_room_v.c \
	print_rooms_v.c \
	print_rooms_queue_v.c \
	enqueue_room.c \
	enqueue_ant.c \
	dequeue_ant.c \
	choose_path.c \
	reset_depth.c \
	assign_depth.c \
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

test:
	@ cd /home/ak/Documents/lem-in_test && sh unit_tests.sh && cd /home/ak/Documents/lem_in
