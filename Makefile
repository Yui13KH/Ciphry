CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lcriterion  # link Criterion for tests

TARGET = ciphry
TEST_TARGET = test_ciphry
BIN_DIR = bin

SRC = $(wildcard src/*.c src/ciphers/*.c src/core/*.c)
OBJ = $(SRC:.c=.o)

# Separate main.o from other objects (so tests can exclude main.o)
MAIN_OBJ = src/core/main.o
CORE_OBJ = $(filter-out $(MAIN_OBJ), $(OBJ))

TEST_SRC = $(wildcard tests/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)

.PHONY: all clean

all: $(TARGET) $(TEST_TARGET)

# Build main program (with main.o)
$(TARGET): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $(OBJ)

# Build test program (without main.o)
$(TEST_TARGET): $(TEST_OBJ) $(CORE_OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $^

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/*.o $(BIN_DIR)/$(TARGET) $(BIN_DIR)/$(TEST_TARGET)
	rm -f $(OBJ) $(TEST_OBJ)
	