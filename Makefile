CC = gcc
#CFLAGS = -Wall -Wextra -Werror 
NAME = fdf
OBJECTS = *.o

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) -L./mlx_linux -lmlx -lXext -lX11 -lm
#Don't forget to add $(CFLAGS) when ready.
$(OBJECTS): *.c
	$(CC) -I./mlx_linux -c *.c
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all