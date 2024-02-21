NAME	=	minitalk

CLIENT	=	client

SERVER	= 	server

NAMELIB	=	libft.a

LIBFT	=	libft/libft.a

all: $(CLIENT) $(SERVER) $(NAMELIB) 

$(NAMELIB):
	$(MAKE) -C libft/.
	cp $(LIBFT) ./ 

$(CLIENT): $(NAMELIB) 
	gcc -Wall -Wextra -Werror client.c $(NAMELIB) -o $(CLIENT)

$(SERVER): $(NAMELIB)
	gcc -Wall -Wextra -Werror server.c $(NAMELIB) -o $(SERVER)

clean:
	@$(MAKE) fclean -C ./libft

fclean: clean
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)
	@rm -rf $(NAMELIB)

re: fclean all