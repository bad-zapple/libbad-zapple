LIB=bad-zapple
NAME=build/lib$(LIB).a
SRC=bad_zapple.cpp
HEADER=bad_zapple.hpp
OBJ=$(SRC:.cpp=.o)
BUILD_DIR=./build
ARGS=

all: $(NAME)

$(NAME): cmake-rule
	make -C $(BUILD_DIR) $(LIB)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

cmake-rule: update-sources
	cmake -B $(BUILD_DIR)

clean:
	make clean -C $(NAME)

fclean:
	rm -rf $(BUILD_DIR)

update-sources: $(BUILD_DIR)
	@sh ./tools/list_sources.sh build/sources.cmake

re: clean all

lsp: update-sources
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B $(BUILD_DIR)

.PHONY: all clean fclean re
