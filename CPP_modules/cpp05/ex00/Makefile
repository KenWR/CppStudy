SRCS = main.cpp Bureaucrat.cpp
INCLUDES = .
OBJS = $(SRCS:.cpp=.o)

NAME = bureaucrat
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS) -I$(INCLUDES)
	$(CC) $(FLAG) $(OBJS) -o $(NAME) -I$(INCLUDES)

%.o : %.cpp -I$(INCLUDES)
	$(CC) $(FLAG) -c $< -o $@ -I$(INCLUDES)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re