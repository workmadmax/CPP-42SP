# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:53:12 by mdouglas          #+#    #+#              #
#    Updated: 2023/11/23 16:11:42 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= mutant

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
							$(RM) -r $(OBJ_DIR)
							
re:							fclean all