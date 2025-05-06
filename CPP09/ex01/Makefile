NAME    = RPN

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp RPN.cpp
OBJS    = $(SRCS:.cpp=.o)
DEPS    = RPN.hpp

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
