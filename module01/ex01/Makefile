NAME							= zombie

CC								= c++
CFLAGS							= -Wall -Wextra -Werror -std=c++98 -g3
OBJS							= $(SRCS:.cpp=.o)

SRCS							= main.cpp \
								  Zombie.cpp \

#color

GREEN							= \033[0;32m
RED								= \033[0;31m
RESET							= \033[0m
YELLOW							= \033[0;33m

all:							$(NAME)

$(NAME):						$(OBJS)
									@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
									@echo "$(GREEN)$(NAME) created.$(RESET)"

%.o:							%.cpp
									@$(CC) $(CFLAGS) -c $< -o $@
									@echo "$(YELLOW)Compiling $<$(RESET)"

clean:
									@echo "$(RED)Deleting objects files$(RESET)"
									rm -rf $(OBJS)
									@echo "$(GREEN)Objects files deleted.$(RESET)"

fclean:							clean
									@echo "$(RED)Deleting $(NAME)$(RESET)"
									rm -rf $(NAME)
									@echo "$(GREEN)$(NAME) deleted.$(RESET)"

re:								fclean all

.PHONY:							all clean fclean re