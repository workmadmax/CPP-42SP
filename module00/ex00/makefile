NAME			= megaphone

SRC				= megaphone.cpp
OBJ				= $(SRC:.cpp=.o)

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98

all:			$(NAME) $(OBJ)

.c.o:		$(SRC)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):			$(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)																