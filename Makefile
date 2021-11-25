CC = clang
CFLAGS = -Wall -Wextra -Werror
VPATH = src

# Source files
SRC_DIR = src
SRC_FILES = main.c

# Header files
HEADER_FILES = 	main.h \
				data.h

# Object files
OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Program name
NAME = push_swap

# Default build
all: $(OBJ_DIR) $(NAME)

run: all
	@ ./$(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_FILES): $(OBJ_DIR)/%.o : %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
