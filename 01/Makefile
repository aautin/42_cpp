NAME:= phonebook

CC:= c++
CFLAGS:= -Werror -Wall -Wextra -std=c++98

SRC_PATH:= src/
OBJ_PATH:= obj/

INC := .
SRC := Contact PhoneBook
SRC := $(addsuffix .cpp, $(addprefix src/, $(SRC)))
OBJ := $(SRC:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

all: $(NAME)

debug: CFLAGS += -g3
debug: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	@mkdir obj

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re