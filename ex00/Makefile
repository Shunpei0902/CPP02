NAME = fixed
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))
INC = $(shell find $(INC_DIR) -type f -name "*.hpp")
SRC_FILES = main.cpp Fixed.cpp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(FLAGS) $(OBJ) -I $(INC_DIR) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re