SERVER_NAME=server
SERVER_SRC=server.c
SERVER_OBJ=${SERVER_SRC:.c=.o}
CLIENT_NAME=client
CLIENT_SRC=client.c
CLIENT_OBJ=${CLIENT_SRC:.c=.o}
CFLAGS=-Wall -Wextra -Werror -I ${LIBFT_DIR}
LIBFT_DIR=libft/
LIBFT_BIN=${LIBFT_DIR}/libft.a
LINK_LIB=-L ${LIBFT_DIR} -lft

all:
	make ${SERVER_NAME}
	make ${CLIENT_NAME}

bonus:
	cd bonus && make all

${SERVER_NAME}: ${SERVER_OBJ} ${LIBFT_BIN} 
	gcc ${CFLAGS} ${SERVER_OBJ} -o $@ ${LINK_LIB}

${CLIENT_NAME}: ${CLIENT_OBJ} ${LIBFT_BIN}
	gcc ${CFLAGS} ${CLIENT_OBJ} -o $@ ${LINK_LIB}

${LIBFT_BIN}:
	cd libft && make

clean: 
	cd bonus && make clean
	rm -rf *.o
	cd ${LIBFT_DIR} && make clean 

fclean: clean
	rm -rf ${SERVER_NAME} ${CLIENT_NAME}
	cd ${LIBFT_DIR} && make fclean
	cd bouns && make fclean

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
