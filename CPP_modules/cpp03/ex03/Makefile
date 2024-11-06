SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
INCLUDES = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = FragTrap
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