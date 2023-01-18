
SUB_FUNCT = sub_function.c 

SERVER = server

CLIENT = client

PRINTF = printf

CFLAGS = -Wall -Werror -Wextra -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

FLAGS = -Wall -Werror -Wextra 

all : 
	
	@make -s -C $(PRINTF)
	@cc $(CFLAGS) client.c $(SUB_FUNCT) -o $(CLIENT)
	@cc $(CFLAGS) server.c -o $(SERVER)
	@echo "Server And Client Are Ready!"


clean :
		@make clean -s -C $(PRINTF)
fclean : clean
		@make fclean -s  -C $(PRINTF)
		@rm -f $(SERVER) $(CLIENT)
		@echo "Server and Client Have Been Cleaned Successfully"

re : fclean all
