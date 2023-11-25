# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 11:18:55 by mdouglas          #+#    #+#              #
#    Updated: 2023/11/25 16:50:03 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= btc

CC							= c++ -std=c++11
CFLAGS						= -Wall -Wextra -Werror

SRC							= main.cpp \
								check_input_date.cpp \
								check_input_value.cpp \
								handle_binary_search.cpp \
								handle_data_base.cpp \
								handle_input.cpp \
								


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