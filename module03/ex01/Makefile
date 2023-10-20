# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:27:19 by madmax42          #+#    #+#              #
#    Updated: 2023/10/20 15:30:35 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME						= clap_trap

CC							= c++ -std=c++98
CFLAGS						= -Wall -Wextra -Werror -g3

VPATH						= ./srcs
SRCS						= main.cpp \
								ClapTrap.cpp \
								ScavTrap.cpp \

OBJS_DIR					= objs
OBJS						= $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

RM							= rm -f
MKDIR						= mkdir -p

$(OBJS_DIR)/%.o: %.cpp
							$(CC) $(CFLAGS) -c $< -o $@

all:						$(NAME)

$(NAME):					$(OBJS_DIR) $(OBJS)
							$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR):
							$(MKDIR) $(OBJS_DIR)

clean:
							$(RM) -r $(OBJS_DIR)


fclean:						clean
							$(RM) $(NAME)

re:							fclean all

.PHONY:						all clean fclean replan
