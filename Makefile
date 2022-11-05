CLIENT		:= client
SERVER		:= server

CLIENT_B	:= client_bonus
SERVER_B	:= server_bonus

CLIENT_DIR	:= ft_client
SERVER_DIR	:= ft_server

CLIENT_B_S	:= $(wildcard $(CLIENT_DIR)/*_bonus.c)
CLIENT_SRCS	:= $(filter-out $(CLIENT_B_S), $(wildcard $(CLIENT_DIR)/*.c))
SERVER_B_S	:= $(wildcard $(SERVER_DIR)/*_bonus.c)
SERVER_SRCS	:= $(filter-out $(SERVER_B_S), $(wildcard $(SERVER_DIR)/*.c))

CLIENT_OBJS	:= $(CLIENT_SRCS:%.c=%.o)
CLIENT_B_O	:= $(CLIENT_B_S:%.c=%.o)
SERVER_OBJS	:= $(SERVER_SRCS:%.c=%.o)
SERVER_B_O	:= $(SERVER_B_S:%.c=%.o)

LIBFT_NAME	:= libft.a
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/$(LIBFT_NAME)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

RM			:= rm -f

all:		$(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
			@$(MAKE) -C $(LIBFT_DIR)

$(CLIENT):	$(CLIENT_OBJS)
			@$(CC) $(CFLAGS) $< -o $@ $(LIBFT)
			@echo "$@ created"

$(SERVER):	$(SERVER_OBJS)
			@$(CC) $(CFLAGS) $< -o $@ $(LIBFT)
			@echo "$@ created"

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

bonus:		$(LIBFT) $(CLIENT_B) $(SERVER_B)

$(CLIENT_B):$(CLIENT_B_O)
			@$(CC) $(CFLAGS) $< -o $@ $(LIBFT)
			@echo "$@ created"

$(SERVER_B):$(SERVER_B_O)
			@$(CC) $(CFLAGS) $< -o $@ $(LIBFT)
			@echo "$@ created"

clean:
			@$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
			@$(RM) $(CLIENT_B_O) $(SERVER_B_O)
			@$(MAKE) clean -C $(LIBFT_DIR)

fclean:		clean
			@$(RM) $(CLIENT) $(SERVER)
			@$(RM) $(CLIENT_B) $(SERVER_B)
			@$(MAKE) fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:	all clean fclean re bonus
