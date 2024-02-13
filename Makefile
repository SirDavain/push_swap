NAME = push_swap

SRC_DIR = ./src
INC_DIR = ./include
LIBFT_DIR = ./libft

SRC = push_swap.c ps_error.c utils.c swap.c push.c rotate.c rev_rotate.c \
		find.c nodes.c set.c sorting.c
OBJ	= $(SRC:%.c=%.o)
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR) -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

HEADERS = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIBS) -o $(NAME)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: NAME clean fclean re
