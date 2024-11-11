SRCS = main.cpp AMateria.cpp Materia.cpp IMateriaSource.cpp MateriaSource.cpp ICharacter.cpp Character.cpp 
INCLUDES = AMateria.hpp Materia.hpp IMateriaSource.hpp MateriaSource.hpp ICharacter.hpp Character.hpp
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