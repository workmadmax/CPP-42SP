# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 10:57:25 by madmax42          #+#    #+#              #
#    Updated: 2023/10/09 10:14:04 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= zombie
SRCS						= main.cpp \
								Zombie.cpp \
								newZombie.cpp \
								randomChump.cpp
								
CC							= c++ 
FLAGS						= -Wall -Wextra -Werror -std=c++98 -g3
OBJS						= $(SRCS:.cpp=.o)

# COLORS
RED							= $(shell tput -Txterm setaf 1)
GREEN						= $(shell tput -Txterm setaf 2)
YELLOW						= $(shell tput -Txterm setaf 3)
RESET						= $(shell tput -Txterm sgr0)

$(NAME): 					$(OBJS)
								@echo "$(YELLOW)Linking...$(RESET)"
								$(CC) $(FLAGS) $(OBJS) -o $(NAME)
								@echo "$(GREEN)Done!$(RESET)"

%.o:						%.cpp
								@echo "$(YELLOW)Compiling $<...$(RESET)"
								$(CC) $(FLAGS) -c $< -o $@
								@echo "$(GREEN)Done!$(RESET)"

all:						$(NAME) $(OBJS)

clean:
								@echo "$(YELLOW)Cleaning...$(RESET)"
								rm -f $(OBJS)
								@echo "$(GREEN)Done!$(RESET)"

fclean: clean
								@echo "$(YELLOW)Full cleaning...$(RESET)"
								rm -f $(NAME)
								@echo "$(GREEN)Done!$(RESET)"

re:							fclean all


.PHONY:						all clean fclean re