# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 14:47:34 by mdouglas          #+#    #+#              #
#    Updated: 2023/11/15 14:48:02 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= iter

CC							= c++ -std=c++98
CFLAGS						= -Wall -Wextra -Werror

SRC							= main.cpp

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