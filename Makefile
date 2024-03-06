# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:23:42 by flo-dolc          #+#    #+#              #
#    Updated: 2024/03/06 17:38:40 by flo-dolc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	src/

SRC			=	check_map.c \
				flood_fill.c \
				free_all.c \
				init.c \
				main.c \
				map_utils.c \
				open_images.c \
				print_map.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR	=	obj/

OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

INCLUDES	=	-Imlx -Ilibft

MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_FLAGS	=	-Llibft -lft

all:			$(NAME)

$(OBJS_DIR):
				mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c | $(OBJS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME):		$(OBJS_DIR) $(OBJS)
				@make -C ./mlx
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

test:			all
				@./$(NAME) ./maps/test1.ber

.PHONY:			all clean fclean re norm
