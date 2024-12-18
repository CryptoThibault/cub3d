# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achevron <achevron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 14:26:00 by achevron          #+#    #+#              #
#    Updated: 2024/11/19 18:29:15 by achevron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
LIBFT = libft
MLX = mlx
FLAGS = -Wall -Wextra -Werror -Iincludes
LFLAGS = -L${MLX} -lmlx -lX11 -lXext -lm

SRCS = srcs/main.c srcs/create_data.c srcs/check_map.c srcs/perror_exit.c \
       srcs/create_window.c srcs/load_textures.c srcs/run_game.c \
       srcs/handle_key.c srcs/utils.c srcs/render.c srcs/render_column.c \
       srcs/select_texture.c srcs/update.c srcs/get_elements.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/$(LIBFT).a $(MLX)/lib$(MLX).a
	$(CC) $(FLAGS) -o $@ $^ ${LFLAGS}

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
