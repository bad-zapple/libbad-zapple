NAME=bad-zapple
BUILD_DIR=./build
TARGET=$(BUILD_DIR)/$(NAME).a
CMAKEFILE=$(BUILD_DIR)/Makefile

all: $(CMAKEFILE)
	make -C $(BUILD_DIR) all

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

tests: $(CMAKEFILE)
	make -C build/ tests

.PHONY: tests 

run-test: all
	ctest --test-dir build

.PHONY: test-run
