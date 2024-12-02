NAME=bad-zapple
BUILD_DIR=./build
TARGET=$(BUILD_DIR)/$(NAME).a
CMAKEFILE=$(BUILD_DIR)/Makefile

from-0-to-test: all
	make run-test

all: $(CMAKEFILE)
	make -C $(BUILD_DIR) $(NAME)

.PHONY: all 

$(TARGET): $(CMAKEFILE)
	make -C $(BUILD_DIR) $(NAME)

clean:
	make clean -C $(NAME)

.PHONY: clean 

fclean:
	rm -rf $(BUILD_DIR)

.PHONY: fclean 

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(CMAKEFILE) : bld

bld: update-sources
	cmake -B $(BUILD_DIR)

.PHONY: bld

update-sources: $(BUILD_DIR)
	@sh ./tools/list_sources.sh build/sources.cmake

.PHONY: update-sources 

lsp: update-sources
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B $(BUILD_DIR)

.PHONY: lsp 

tests: 
	make -C build/ tests

.PHONY: tests 

run-test: tests
	./build/tests

.PHONY: test-run
