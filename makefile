CC = cc
CFLAG = -std=c89 -Wall -Wextra -Isrc
LDFLAGS = -lm -lSDL2
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = $(BUILD_DIR)/game_of_life

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	@mkdir -p output
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/core.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: r
r:
	./$(BUILD_DIR)/game_of_life

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) 
	rm -rf output
