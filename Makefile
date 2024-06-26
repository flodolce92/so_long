# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:23:42 by flo-dolc          #+#    #+#              #
#    Updated: 2024/06/19 19:07:25 by flo-dolc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	src/

SRC			=	print_map.c \
				print_obj.c \
				map_utils.c \
				main.c \
				free_all.c \
				flood_fill.c \
				hooks.c \
				open_images.c \
				check_map.c \
				init.c \
				moves.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR	=	obj/

OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

INCLUDES	=	-I/usr/include -Imlx_linux -O3 -Ilibft

MLX_FLAGS	=	-Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_FLAGS	=	-Llibft -lft

all:			$(NAME)

$(OBJS_DIR):
				mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c | $(OBJS_DIR)
				$(CC) $(CFLAGS) -c -g $< -o $@ $(INCLUDES)

$(NAME):		$(OBJS_DIR) $(OBJS)
				@make -C ./mlx_linux
				@make -C ./libft
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

clean:
				$(RM) $(OBJS)
				$(RM) -r $(OBJS_DIR)
				@make -C ./mlx_linux clean
				@make -C ./libft clean

fclean:			clean
				$(RM) $(NAME)
				@make -C ./libft fclean

re:				fclean all

norm:
				@norminette $(SRCS) $(SRCS_DIR)so_long.h

test:			all
				@./$(NAME) ./maps/test1.ber

bonus:			all
				@./$(NAME) ./maps/enemy_map.ber

.PHONY:			all clean fclean re norm test bonus
