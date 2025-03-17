SRCS = main.cpp Span.cpp
HEADERS = Span.hpp
INCLUDES = .
OBJS = $(SRCS:.cpp=.o)

NAME = span
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

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