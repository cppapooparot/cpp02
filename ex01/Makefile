NAME = fixed

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Fixed.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re