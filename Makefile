NAME = cub3d

CC = cc
FLAGS = -Wall -Wextra -Werror -Iincludes
LIBFT = libft

SRCS = srcs/main.c srcs/create_data.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/$(LIBFT).a
	$(CC) $(FLAGS) -o $@ $^

$(LIBFT)/$(LIBFT).a:
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
