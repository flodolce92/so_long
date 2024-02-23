# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:23:42 by flo-dolc          #+#    #+#              #
#    Updated: 2024/02/23 23:17:53 by flo-dolc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(shell find ./src -name "*.c")

OBJS		=	$(SRCS:.c=.o)

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

INCLUDES	=	-Imlx -Ilibft

MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_FLAGS	=	-Llibft -lft

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

$(NAME):	$(OBJS)
			@make -C ./mlx
			@make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

clean:
			$(RM) $(OBJS)
			@make -C ./libft clean

fclean:		clean
			$(RM) $(NAME)
			@make -C ./libft fclean

re:			fclean all

norm:
			@norminette $(shell find ./src -name "*.c")

.PHONY:		all clean fclean re norm
