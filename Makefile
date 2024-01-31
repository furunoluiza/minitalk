SRC = server.c client.c
LIBFT = libft.a
NAME = minitalk
OBJ = $(SRC:.c=.o)
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ) libft/$(LIBFT) -o server

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all



.PHONY: all clean fclean re
