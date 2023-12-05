EXEC = Simulation

CC = c++
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

BIN_DIR = bin
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
# LIB_DIR = lib_directory

SRC = $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# LIB = $(LIB_DIR)/your_lib.a
# LIBS = -L$(LIB_DIR) -lLib -lLib -lLib -lLib (if you have multiple libs)

all: $(EXEC)

$(EXEC): $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) -I $(INC_DIR) $(LIBS) -o $@
	@mkdir -p $(BIN_DIR)
	@mv $(EXEC) $(BIN_DIR)/$(EXEC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

#$(LIB):
#	@$(MAKE) -C $(LIB_DIR) (if a lib needs to be compiled)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
