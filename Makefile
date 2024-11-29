NAME=bad-zapple
BUILD_DIR=./build
TARGET=$(BUILD_DIR)/$(NAME).a

all: $(TARGET)

.PHONY: all 

$(TARGET): cmake-rule
	make -C $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

cmake-rule: update-sources
	cmake -B $(BUILD_DIR)

.PHONY: cmake-rule

clean:
	make clean -C $(NAME)

.PHONY: clean 

fclean:
	rm -rf $(BUILD_DIR)

.PHONY: fclean 

update-sources: $(BUILD_DIR)
	@sh ./tools/list_sources.sh build/sources.cmake

.PHONY: update-sources 

re: clean all

.PHONY: re

lsp: update-sources
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B $(BUILD_DIR)

.PHONY: lsp 
