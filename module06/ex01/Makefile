# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:55:21 by mdouglas          #+#    #+#              #
#    Updated: 2023/11/12 11:55:57 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= serialize

CC							= c++ -std=c++98
CFLAGS						= -Wall -Wextra -Werror -g3


SRCS						= main.cpp \
								Serializer.cpp \
								
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
