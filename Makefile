CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = ciphry

SRC = $(wildcard src/*.c src/ciphers/*.c)
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean