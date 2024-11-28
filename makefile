NAME=libbad-zapple
SRC=bad_zapple.cpp
HEADER=bad_zapple.hpp
OBJ=$(SRC:.cpp=.o)

CC=g++
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
