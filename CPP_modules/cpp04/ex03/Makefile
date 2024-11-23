# directory config
ABSTRACT_INCLUDE = abstract/include
ABSTRACT_SRC = abstract/src
CONCRETE_INCLUDE = concrete/include
CONCRETE_SRC = concrete/src

# Abstract & Interface srcs
ABSTRACT_SRCS = $(ABSTRACT_SRC)/AMateria.cpp \
                $(ABSTRACT_SRC)/IMateriaSource.cpp \
                $(ABSTRACT_SRC)/ICharacter.cpp

# Concrete srcs
CONCRETE_SRCS = $(CONCRETE_SRC)/Ice.cpp \
                $(CONCRETE_SRC)/Cure.cpp \
                $(CONCRETE_SRC)/MateriaSource.cpp \
                $(CONCRETE_SRC)/Character.cpp


# Header includes
HEADERS = $(ABSTRACT_INCLUDE)/AMateria.hpp \
          $(ABSTRACT_INCLUDE)/IMateriaSource.hpp \
          $(ABSTRACT_INCLUDE)/ICharacter.hpp \
          $(CONCRETE_INCLUDE)/Ice.hpp \
          $(CONCRETE_INCLUDE)/Cure.hpp \
          $(CONCRETE_INCLUDE)/MateriaSource.hpp \
          $(CONCRETE_INCLUDE)/Character.hpp \

# Set Objects
ABSTRACT_OBJS = $(ABSTRACT_SRCS:.cpp=.o)
CONCRETE_OBJS = $(CONCRETE_SRCS:.cpp=.o)
OBJS = $(ABSTRACT_OBJS) $(CONCRETE_OBJS)

NAME = materia
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(ABSTRACT_INCLUDE) -I$(CONCRETE_INCLUDE) -I.

all : $(NAME)

$(NAME) : $(OBJS) main.o
	$(CXX) $(CXXFLAGS) $(OBJS) main.o -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

loud : CXXFLAGS += -DLOUD
loud : re

clean :
	@rm -f $(OBJS) main.o

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re