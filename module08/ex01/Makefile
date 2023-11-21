# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 12:01:42 by mdouglas          #+#    #+#              #
#    Updated: 2023/11/21 12:23:48 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= span

CC							= c++ -std=c++98
CFLAGS						= -Wall -Wextra -Werror

SRC							= main.cpp \
							  	Span.cpp

OBJ							= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
OBJ_DIR						= obj

RM							= rm -f
MKDIR						= mkdir -p

$(OBJ_DIR)/%.o: 			%.cpp
							$(MKDIR) $(OBJ_DIR)
							$(CC) $(CFLAGS) -c $< -o $@

all:						$(NAME)

$(NAME):					$(OBJ)
							$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
							$(MKDIR) $(OBJ_DIR)
							
clean:
							$(RM) $(OBJ)

fclean:						clean
							$(RM) $(NAME)
							
re:							fclean all