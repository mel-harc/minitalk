SUB_FUNCT = sub_function.c 

SERVER = server

CLIENT = client

CLINET_BONUS = 	client_bonus

SERVER_BONUS = server_bonus

PRINTF = printf

CFLAGS = -Wall -Werror -Wextra printf/libftprintf.a

all : 
	
	@make -s -C $(PRINTF)
	@cc $(CFLAGS) client.c $(SUB_FUNCT) -o $(CLIENT)
	@cc $(CFLAGS) server.c -o $(SERVER)
	@echo "Server And Client Are Ready Now!"

bonus :
		@make -s -C ${PRINTF}
		@cc $(CFLAGS) clinet_bonus.c $(SUB_FUNCT) -o $(CLINET_BONUS)
		@cc $(CFLAGS) server_bonus.c -o $(SERVER_BONUS)
		@echo "server_bonus And client_bonus Are Ready Now!"


clean :
		@make clean -s -C $(PRINTF)
fclean : clean
		@rm -f $(SERVER) $(CLIENT) 
		@rm -f $(SERVER_BONUS) $(CLINET_BONUS)
		@echo "Server and Client Cleaned"

re : fclean all



