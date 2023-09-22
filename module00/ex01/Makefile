NAME					= phonebook

SRCS					= main.cpp PhoneBook.cpp Contact.cpp

CC						= c++
FLAGS					= -Wall -Wextra -Werror -std=c++98

OBJS					= $(SRC:.c=.o)

$(NAME):				$(OBJS)
							$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all:					$(NAME) $(OBJS)

%.o:					%.c
							$(CC) $(FLAGS) -c $< -o $@

clean:
						rm -f $(NAME)

fclean:					clean

re:						fclean all

.PHONY:					all clean fclean re