CC = clang
CFLAGS = -Wall -Wextra -Werror
VPATH = src

# Source files
SRC_DIR = src
SRC_FILES = main.c

# Header files
HEADER_FILES = 	main.h \
				data.h

# Release object files
RELEASE_OBJ_DIR = release_obj
RELEASE_OBJ_FILES = $(SRC_FILES:%.c=$(RELEASE_OBJ_DIR)/%.o)

# Debug object files
DEBUG_OBJ_DIR = debug_obj
DEBUG_OBJ_FILES = $(SRC_FILES:%.c=$(DEBUG_OBJ_DIR)/%.o)

# Program names
NAME = push_swap
DBGEXE = debug_push_swap

# Default build
all: $(RELEASE_OBJ_DIR) $(NAME)

# Debug build
debug: CFLAGS += -g -fsanitize=address
debug: $(DEBUG_OBJ_DIR) $(DBGEXE)

run: all
	@ ./$(NAME)

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
	$(CC) $(CFLAGS) $^ -o $@

$(DEBUG_OBJ_FILES): $(DEBUG_OBJ_DIR)/%.o : %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(RELEASE_OBJ_DIR) $(DEBUG_OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(DBGEXE)

re: fclean all

.PHONY = all debug clean fclean re
