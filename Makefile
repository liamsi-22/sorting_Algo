NAME = push_swap
CC = gcc -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror

SRC = atoi.c check_minmax.c checkdouble.c checknumbers.c turk_algo.c\
      instructions_a.c instructions_a_b.c instructions_b.c join.c \
      lst.c pushswap.c split.c stackinit.c check_order.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
