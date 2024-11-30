NAME=bad-zapple
BUILD_DIR=./build
TARGET=$(BUILD_DIR)/$(NAME).a

all: 
	make -C $(BUILD_DIR) $(NAME)

.PHONY: all 

$(TARGET): 
	make -C $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	make clean -C $(NAME)

.PHONY: clean 

fclean:
	rm -rf $(BUILD_DIR)

.PHONY: fclean 

update-cmake: update-sources
	cmake -B $(BUILD_DIR)

.PHONY: update-cmake

update-sources: $(BUILD_DIR)
	@sh ./tools/list_sources.sh build/sources.cmake

.PHONY: update-sources 

re: clean all

.PHONY: re

lsp: update-sources
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B $(BUILD_DIR)

.PHONY: lsp 
