CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -lXext -lX11 -lm -lbsd
LIBS = libft/libft.a mlx_linux/libmlx.a
NAME = fdf
OBJECTS = *.o

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft/ all
	$(CC) -o $(NAME) $(OBJECTS) $(CFLAGS) $(LIBS) $(FRAMEWORKS)
#Don't forget to add $(CFLAGS) when ready.
$(OBJECTS): *.c
	$(CC) $(CFLAGS) -I./mlx_linux -c *.c
clean:
	@make -C libft/ clean
	rm -f *.o
fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)
re: fclean all
norminette:
	norminette *.c *.h