SRCS = main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp
INCLUDES = AAnimal.hpp Dog.hpp Cat.hpp Brain.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = brainAnimal
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS) $(INCLUDES)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	$(CC) $(FLAG) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re