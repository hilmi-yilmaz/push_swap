CC = clang
CFLAGS = -Wall -Wextra -Werror
CFLAGSDBG = $(CFLAGS) -g
VPATH = src

# Source files
SRC_DIR = src
SRC_FILES = main.c \
			input_validation.c \
			atoi_with_int_overflow_check.c \
			init_stacks.c \
			sorting_algorithms.c \
			operations.c \
			sort_3_and_5.c \
			radix_sort.c \
			utils.c


# Header files
HEADER_FILES = 	main.h \
				data.h \
				input_validation.h \
				atoi_with_int_overflow_check.h \
				init_stacks.h \
				sorting_algorithms.h \
				operations.c \
				sort_3_and_5.h \
				radix_sort.h \
				utils.h

# # Unity files
UNITY_CONFIG_DEFINES = 	-D UNITY_OUTPUT_COLOR \
						-D UNITY_FIXTURE_NO_EXTRAS

UNITY_INCL = 	-I./unity/src/ \
				-I./unity/extras/fixture/src

# Unit test files
TEST_FILES = 	unity/src/unity.c \
				unity/extras/fixture/src/unity_fixture.c \
				unity/extras/memory/src/unity_memory.c \
				test/main/all_tests.c \
				test/main/all_tests_runner.c \
				test/test_atoi_with_int_overflow_check.c \
				src/atoi_with_int_overflow_check.c \
				test/test_input_validation.c \
				src/input_validation.c \
				test/test_sorting_algorithms.c \
				src/sorting_algorithms.c \
				test/test_init_stacks.c \
				src/init_stacks.c \
				test/test_operations.c \
				src/operations.c \
				test/test_radix_sort.c \
				src/radix_sort.c \
				test/test_sort_3_and_5.c \
				src/sort_3_and_5.c \
				src/utils.c

# Release object files
RELEASE_OBJ_DIR = release_obj
RELEASE_OBJ_FILES = $(SRC_FILES:%.c=$(RELEASE_OBJ_DIR)/%.o)

# Debug object files
DEBUG_OBJ_DIR = debug_obj
DEBUG_OBJ_FILES = $(SRC_FILES:%.c=$(DEBUG_OBJ_DIR)/%.o)

# Test object files
TEST_OBJ_DIR = test_obj
TEST_OBJ_FILES= $(TEST_FILES:%.c=$(TEST_OBJ_DIR)/%.o)

# Libft
LIBFT = libft.a

# Program names
NAME = push_swap
DBGEXE = debug_push_swap
TESTEXE = test_push_swap

# Default build
all: $(RELEASE_OBJ_DIR) $(LIBFT) $(NAME)

# Debug build
debug: $(DEBUG_OBJ_DIR) $(LIBFT) $(DBGEXE)

run: all
	./$(NAME) 4 3 2 1 0

test: $(TEST_OBJ_DIR) $(LIBFT) $(TESTEXE)

test_run: test
	@./$(TESTEXE) -v

# Create release object directory
$(RELEASE_OBJ_DIR):
	mkdir -p $@

# Create debug object directory
$(DEBUG_OBJ_DIR):
	mkdir -p $@

# # Create test object directory
$(TEST_OBJ_DIR):
	mkdir -p $@

# Libft
$(LIBFT):
	make -C libft

# Build release
$(NAME): $(RELEASE_OBJ_FILES)
	$(CC) $(CFLAGS) $^ libft/$(LIBFT) -o $@

$(RELEASE_OBJ_FILES): $(RELEASE_OBJ_DIR)/%.o : %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

# Build debug
$(DBGEXE): $(DEBUG_OBJ_FILES)
	$(CC) $(CFLAGSDBG) $^ libft/$(LIBFT) -o $@

$(DEBUG_OBJ_FILES): $(DEBUG_OBJ_DIR)/%.o : %.c $(HEADER_FILES)
	$(CC) $(CFLAGSDBG) -c $< -o $@

# Unit tests
$(TESTEXE): $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) $^ libft/$(LIBFT) -o $@

$(TEST_OBJ_FILES): $(TEST_OBJ_DIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(UNITY_CONFIG_DEFINES) $(UNITY_INCL) -c $< -o $@

clean:
	rm -rf $(RELEASE_OBJ_DIR) $(DEBUG_OBJ_DIR) $(TEST_OBJ_DIR)
	make fclean -C libft/

fclean: clean
	rm -f $(NAME) $(DBGEXE) $(TESTEXE)

re: fclean all

.PHONY = all debug test clean fclean re
