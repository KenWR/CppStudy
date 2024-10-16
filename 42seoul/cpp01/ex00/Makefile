SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
INCLUDES = Zombie.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = BraiiiiiiinnnzzzZ
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS) $(INCLUDES)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAG) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re