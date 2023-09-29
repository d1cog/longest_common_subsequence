CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
COMPILE_FLAGS = -c
LDFLAGS =
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DEPS = include/longest_common_subsequence.h
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/longest_common_subsequence.o
BIN = $(BIN_DIR)/main

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) $(CFLAGS) -o $@ $<

$(BIN): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(OBJ) $(BIN)
