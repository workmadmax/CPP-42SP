# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 16:15:11 by madmax42          #+#    #+#              #
#    Updated: 2023/10/29 19:36:28 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME						= brain

CC							= c++ -std=c++98
CFLAGS						= -Wall -Wextra -Werror -g3

INCLUDES					= -I./includes

VPATH						= ./srcs
SRCS						= main.cpp \
								AAnimal.cpp \
								Dog.cpp \
								Cat.cpp \
								Brain.cpp
								
OBJS_DIR					= objs
OBJS						= $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

RM							= rm -f
MKDIR						= mkdir -p

$(OBJS_DIR)/%.o: %.cpp
							$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all:						$(NAME)

$(NAME):					$(OBJS_DIR) $(OBJS)
							$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES)

$(OBJS_DIR):
							$(MKDIR) $(OBJS_DIR)

clean:
							$(RM) -r $(OBJS_DIR)


fclean:						clean
							$(RM) $(NAME)

re:							fclean all

.PHONY:						all clean fclean replan
