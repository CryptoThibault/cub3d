# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achevron <achevron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 14:26:00 by achevron          #+#    #+#              #
#    Updated: 2024/09/12 19:01:18 by tchalaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
FLAGS = -Wall -Wextra -Werror -Iincludes
LFLAGS = -L${MLX} -L${LIBFT} -lmlx -lX11 -lXext -lft -lm
LIBFT = libft
MLX = mlx

SRCS = srcs/main.c srcs/create_data.c srcs/check_map.c srcs/perror_exit.c \
       srcs/create_window.c srcs/load_textures.c srcs/run_game.c srcs/handle_key.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/$(LIBFT).a $(MLX)/lib$(MLX).a
	$(CC) $(FLAGS) $(LFLAGS) -o $@ $^

$(LIBFT)/$(LIBFT).a:
	make -C $(LIBFT)

$(MLX)/lib$(MLX).a:
	make -C $(MLX)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette includes srcs libft

.PHONY: all norm clean fclean re
