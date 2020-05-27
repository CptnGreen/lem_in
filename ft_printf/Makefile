# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:25:21 by fcatina           #+#    #+#              #
#    Updated: 2020/02/26 12:34:10 by slisandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re libft exec norm memcheck

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
EXEC = ft_printf

SRC_DIR = src
SRC_RAW = \
	ft_printf.c \
	ft_itoa_base.c \
	x_ft_itoa_base.c\
	ft_itoa_unsigned_base.c \
	ft_itoa_unsigned_base.c \
	handle_c.c \
	handle_s.c \
	handle_o.c \
	handle_u.c \
	handle_xxp.c \
	handle_id.c \
	handle_f.c \
	handle_percent.c \
	handle_precision.c \
	putchar_and_count.c \
	putstr_and_count.c \
	print_string_ouxxp.c \
	process_flags.c \
	reset_struct.c \
	ft_dtoa.c \
	ft_ldtoa.c \
	get_s_f.c \
	get_s_o.c \
	get_s_xx.c \
	fix_s.c
SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))

MAIN_RAW = main.c
MAIN = $(addprefix $(SRC_DIR)/,$(MAIN_RAW))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_RAW:.c=.o))




all: $(NAME)

$(EXEC): $(NAME)
	@ gcc $(CFLAGS) -o $(EXEC) $(MAIN) -I "includes/" -I "libft/includes/" -L . -lftprintf -L "libft/" -lft
$(NAME): libft $(OBJ_DIR) $(OBJ)
	@ cp libft/libft.a $(NAME)
	@ ar -rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
libft:
	@ make -C libft/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ gcc $(CFLAGS) -I "includes/" -I "libft/includes/" -c $< -o $@
$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)


exec: $(EXEC)

clean:
	@ rm -rf $(OBJ_DIR)
	@ make -C libft/ clean
fclean: clean
	@ rm -f $(NAME)
	@ make -C libft/ fclean
re: fclean all

norm: fclean
	@ rm -f $(EXEC)
	@ clear && clear && clear
	@ /Users/slisandr/.scripts/colorised_norm.sh

memcheck: exec
	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(EXEC)
	@ vim valgrind-out.txt

test: exec
	@ clear && clear && clear
	@ ./$(EXEC)
