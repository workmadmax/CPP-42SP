# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 16:15:11 by madmax42          #+#    #+#              #
#    Updated: 2023/11/06 20:17:06 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME						= Aform

CC							= c++ -std=c++98
CFLAGS						= -Wall -Wextra -Werror -g3

INCLUDES					= -I./includes

VPATH						= ./srcs
SRCS						= main.cpp \
								AForm.cpp \
								Bureaucrat.cpp \
								ShrubberyCreationForm.cpp \
								RobotomyRequestForm.cpp \
								PresidentialPardonForm.cpp \
								testsForms.cpp \
								
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
