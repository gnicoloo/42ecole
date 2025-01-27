SERVER = server
CLIENT = client
RM = rm -f
FLAGS = -Wall -Wextra -Werror -L./libft -l:libft.a -Ilibft -g

all: $(SERVER) $(CLIENT)


$(SERVER):
	make -C libft
#	cc $(FLAGS) -o $(SERVER) server.c
	cc server.c $(FLAGS) -L./libft -l:libft.a   -Ilibft -o server


$(CLIENT):
	make -C libft
#	cc $(FLAGS) -o $(CLIENT) client.c
	cc client.c $(FLAGS) -L./libft -l:libft.a   -Ilibft -o client

fclean:
	${RM} ${SERVER} ${CLIENT}
	${MAKE} fclean -C libft
clean:
	${RM} *.o
	${MAKE} clean -C libft


re: fclean all

.PHONY : all clean fclean re
