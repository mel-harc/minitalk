SR = client.c server.c sub_function.c

CC = cc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJECT : ${SR:.c=.o}

${SERVER} : 


clean :
		${RM} ${SR}

re : ${}
	clean ${}