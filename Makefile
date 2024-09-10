NAME = cub3D

CC = cc
FLAGS = -Wall -Wextra -Werror -Iincludes
LFLAGS = -L${MLX} -L${LIBFT} -lmlx -lX11 -lXext -lft -lm
LIBFT = libft
MLX = mlx

SRCS = srcs/create_data.c srcs/event_handlers.c srcs/main.c \
		perror_exit.c srcs/win_manager.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/$(LIBFT).a $(MLX)/$(MLX).a
	$(CC) $(FLAGS) $(LFLAGS) -o $@ $^

$(LIBFT)/$(LIBFT).a:
	make -C $(LIBFT)

$(MLX)/$(MLX).a:
	make -C $(MLX)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

norme:
	norminette includes/ libft/ srcs/

clean:
	rm -f $(OBJS)
	make -C ${LIBFT} clean

fclean: clean
	rm -f $(NAME)
	make -C ${MLX} clean
	make -C ${LIBFT} fclean

re: fclean all

.PHONY: all norme clean fclean re
