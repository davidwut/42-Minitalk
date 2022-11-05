NAME			:= libft.a

SRC_DIR			:= ./src
BUILD_DIR		:= ./build

SRCS			:= $(wildcard $(SRC_DIR)/*.c)
OBJS			:= $(SRCS:%=$(BUILD_DIR)/%.o)

CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror

AR				:= ar -rcs
RM				:= rm -rf

# Colors
MAIN 		:= \033[38;5;50m
PLOAD 		:= \033[38;5;119m
GREEN 		:= \033[38;5;47m
BLUE 		:= \033[0;38;5;12m
ORANGE 		:= \033[0;38;5;214m
RED 		:= \033[1;31m
PURPLE		:=\033[0;35m
END 		:= \033[0m
BOLD 		:= \033[1m
# MSG Prefixes
INFO 		:= $(MAIN)INFO$(END)
WARN 		:= $(ORANGE)WARNING$(END)
IMPORTANT 	:= $(ORANGE)IMPORTANT$(END)
FAILED 		:= $(RED)FAIL$(END)
DEBUG 		:= $(ORANGE)DEBUG$(END)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(INFO) $(NAME) created"

$(BUILD_DIR)/%.c.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "$(INFO) $< compiled"

clean:
			@$(RM) $(BUILD_DIR)
			@echo "$(INFO) $(BUILD_DIR) deleted"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(INFO) $(NAME) deleted"

re:			fclean all

.PHONY:		all clean fclean re
