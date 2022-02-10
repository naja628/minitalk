CLIENT_SRC=client.c
SERVER_SRC=server.c
SERVER_NAME=server
CLIENT_NAME=client

# Note: 1 .c per exe so no .o are required

all: $(CLIENT_NAME) $(SERVER_NAME)
	@#empty

$(SERVER_NAME): $(SERVER_SRC)
	gcc -o $(SERVER_NAME) $(SERVER_SRC)
	
$(CLIENT_NAME): $(CLIENT_SRC)
	gcc -o $(CLIENT_NAME) $(CLIENT_SRC)

.PHONY: all
