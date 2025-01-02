CC = c++
NAME = Bureaucrat
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Bureaucrat.cpp
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CPPFLAGS) -I$(INCLUDE_DIR) $^ -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)/*.o

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re