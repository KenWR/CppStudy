SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp IMateriaSource.cpp MateriaSource.cpp ICharacter.cpp Character.cpp 
INCLUDES = AMateria.hpp Ice.hpp Cure.hpp IMateriaSource.hpp MateriaSource.hpp ICharacter.hpp Character.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = materia
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