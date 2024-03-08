# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:23:42 by flo-dolc          #+#    #+#              #
#    Updated: 2024/03/08 03:24:24 by flo-dolc         ###   ########.fr        #
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

#INCLUDES	=	-Imlx -Ilibft
INCLUDES	=	-I/usr/include -Imlx_linux -O3 -Ilibft

#MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_FLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_FLAGS	=	-Llibft -lft

all:			$(NAME)

$(OBJS_DIR):
				mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c | $(OBJS_DIR)
				$(CC) $(CFLAGS) -c -g $< -o $@ $(INCLUDES)

$(NAME):		$(OBJS_DIR) $(OBJS)
#@make -C ./mlx
				@make -C ./mlx_linux
				@make -C ./libft
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

clean:
				$(RM) $(OBJS)
#@make -C ./mlx clean
#@make -C ./libft clean

fclean:			clean
				$(RM) $(NAME)
#@make -C ./libft fclean

re:				fclean all

norm:
				@norminette $(SRCS)
				@norminette -R CheckDefine $(SRCS_DIR)so_long.h

test:			all
				@./$(NAME) ./maps/test1.ber

.PHONY:			all clean fclean re norm
