SRCS = main.cpp PmergeMe.cpp
HEADERS = PmergeMe.hpp
INCLUDES = .
OBJS = $(SRCS:.cpp=.o)

NAME = PmergeMe
CC = c++
FLAG =  -std=c++98
# -Wall -Wextra -Werror
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME) -I$(INCLUDES)

%.o : %.cpp $(HEADERS)
	$(CC) $(FLAG) -c $< -o $@ -I$(INCLUDES)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re