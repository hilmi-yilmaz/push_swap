CC = clang
CFLAGS = -Wall -Wextra -Werror
CFLAGSDBG = $(CFLAGS) -g -fsanitize=address
VPATH = src

# Source files
SRC_DIR = src
SRC_FILES = main.c

# Header files
HEADER_FILES = 	main.h \
				data.h

# Unity files
UNITY_SRC = unity/src/unity.c \
			unity/extras/fixture/src/unity_fixture.c

UNITY_INCL = 	-I./unity/src/ \
				-I./unity/extras/fixture/src \
				-I./unity/extras/memory/src

# Unit test files
TEST_FILES = 	test/main/all_tests.c \
				test/test_atoi_with_int_overflow_check.c

SRC_FILES_TO_TEST = src/atoi_with_int_overflow_check.c

# Release object files
RELEASE_OBJ_DIR = release_obj
RELEASE_OBJ_FILES = $(SRC_FILES:%.c=$(RELEASE_OBJ_DIR)/%.o)

# Debug object files
DEBUG_OBJ_DIR = debug_obj
DEBUG_OBJ_FILES = $(SRC_FILES:%.c=$(DEBUG_OBJ_DIR)/%.o)

# Libft
LIBFT = libft.a

# Program names
NAME = push_swap
DBGEXE = debug_push_swap
TESTEXE = test_push_swap

# Default build
all: $(RELEASE_OBJ_DIR) $(LIBFT) $(NAME)

# Debug build
debug: $(DEBUG_OBJ_DIR) $(DBGEXE)

run: all
	@ ./$(NAME)

test: $(LIBFT) $(TESTEXE)

# Create release object directory
$(RELEASE_OBJ_DIR):
	mkdir -p $@

# Create debug object directory
$(DEBUG_OBJ_DIR):
	mkdir -p $@

# Build release
$(NAME): $(RELEASE_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(RELEASE_OBJ_FILES): $(RELEASE_OBJ_DIR)/%.o : %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

# Build debug
$(DBGEXE): $(DEBUG_OBJ_FILES)
	$(CC) $(CFLAGSDBG) $^ -o $@

$(DEBUG_OBJ_FILES): $(DEBUG_OBJ_DIR)/%.o : %.c $(HEADER_FILES)
	$(CC) $(CFLAGSDBG) -c $< -o $@

# Unit tests
$(TESTEXE):
	@$(CC) $(CFLAGS) $(UNITY_SRC) $(UNITY_INCL) $(TEST_FILES) $(SRC_FILES_TO_TEST) libft/$(LIBFT) -o $@
	@ - ./$@
	@rm -f $@

# Libft
$(LIBFT):
	make -C libft

clean:
	rm -rf $(RELEASE_OBJ_DIR) $(DEBUG_OBJ_DIR)
	make fclean -C libft/

fclean: clean
	rm -f $(NAME) $(DBGEXE)

re: fclean all

.PHONY = all debug test clean fclean re
