NAME = minitalk
SRC_C = client.c
SRC_S = server.c
NAMELIB = libft.a
LIBFT = libft/libft.a
NAME_C = client
NAME_S = server

$(NAME_S) : $(NAMELIB)
	gcc -Wall -Werror -Wextra server.c -I include $(NAMELIB) -o $(NAME_S)

$(NAME_C) : $(NAMELIB)
	gcc -Wall -Werror -Wextra client.c -I include $(NAMELIB) -o $(NAME_C)

$(NAMELIB) :
	$(MAKE) -C libft/.
	cp $(LIBFT) ./

all: $(NAME_C) $(NAME_S) $(LIBFT)

clean:
	@$(MAKE) fclean -C ./libft

fclean: clean
	rm -rf $(NAME_S)
	rm -rf $(NAME_C)
	rm -rf $(NAMELIB)

re: fclean all