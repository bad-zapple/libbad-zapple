NAME=libbad-zapple.a
SRC=bad_zapple.cpp SocketW.cpp
HEADER=bad_zapple.hpp LibBadZapple.hpp SocketW.hpp
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
