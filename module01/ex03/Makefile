# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:01:31 by madmax42          #+#    #+#              #
#    Updated: 2023/10/09 16:54:03 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 14:39:02 by madmax42          #+#    #+#              #
#    Updated: 2023/10/09 14:42:40 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = soldier

SRCS = main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp
		

OBJS = $(SRCS:.cpp=.o)

CC = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re