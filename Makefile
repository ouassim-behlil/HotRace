NAME = hotrace

CC = cc
CFLAGS = -Wall -Wextra -Werror -I src/include

SRC = \
	src/entry.c \
	src/hash.c \
	src/hashmap.c \
	src/insert.c \
	src/lookup.c \
	src/main.c \
	src/read_params.c \
	src/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re