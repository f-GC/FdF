OBJECTS = *.o
SRCS = *.c get_next_line/*.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRCS)
	$(CC) -g $(CFLAGS) $(SRCS)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all