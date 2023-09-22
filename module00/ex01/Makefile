NAME					= phonebook

SRCS					= main.cpp Phonebook.cpp Contact.cpp

CC						= c++
FLAGS					= -Wall -Wextra -Werror -std=c++98

OBJS					= $(SRC:.cpp=.o)

$(NAME):				$(OBJS)
							$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all:					$(NAME) $(OBJS)

%.o:					%.cpp
							$(CC) $(FLAGS) -c $< -o $@

clean:
						rm -rf $(NAME)

fclean:					clean

re:						fclean all

.PHONY:					all clean fclean re