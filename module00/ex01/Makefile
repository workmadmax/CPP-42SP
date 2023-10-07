NAME = phonebook
SRCS = main.cpp PhoneBook.cpp Contact.cpp
CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
OBJS = $(SRCS:.cpp=.o)

# Define as cores
RED = $(shell tput -Txterm setaf 1)
GREEN = $(shell tput -Txterm setaf 2)
YELLOW = $(shell tput -Txterm setaf 3)
RESET = $(shell tput -Txterm sgr0)

$(NAME): $(OBJS)
		@echo "$(YELLOW)Linking...$(RESET)"
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)
		@echo "$(GREEN)Done!$(RESET)"

%.o: %.cpp
		@echo "$(YELLOW)Compiling $<...$(RESET)"
		   $(CC) $(FLAGS) -c $< -o $@
		@echo "$(GREEN)Done!$(RESET)"

all: $(NAME) $(OBJS)

clean:
		@echo "$(YELLOW)Cleaning...$(RESET)"
		rm -f $(OBJS)
		@echo "$(GREEN)Done!$(RESET)"

fclean: clean
		@echo "$(YELLOW)Full cleaning...$(RESET)"
		rm -f $(NAME)
		@echo "$(GREEN)Done!$(RESET)"

re: fclean all



.PHONY: all clean fclean re