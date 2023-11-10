SRC_DIR := src
OBJ_DIR := obj
TARGET_DIR := bin
TARGET := $(TARGET_DIR)/main

# Find all .c files in subdirectories of SRC_DIR
SRC_FILES := $(shell find $(SRC_DIR) -type f -name "*.c")

# Generate object file paths based on source file paths
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

HEADER_FILES := $(shell find $(SRC_DIR)/include -type f -name "*.h")

CFLAGS := -Wall -Wextra -g -fsanitize=address
CFLAGS := -Wall -Wextra -g
LIBS := -lSDL2 -lm

all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	gcc $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(@D)
	gcc $(CFLAGS) $^ -o $@ $(LIBS)

run: $(TARGET)
	$(TARGET)

install: $(TARGET) $(OBJ_FILES)
	gcc -shared -o bin/libvictor.so obj/Victor.o
	sudo install -m 644 bin/libvictor.so /usr/local/lib/

	sudo mkdir -p /usr/local/include/Victor/
	sudo install -m 644 $(HEADER_FILES) /usr/local/include/Victor/
	@echo "Victor library installed successfully."

uninstall:
	sudo rm /usr/local/lib/libvictor.so
	sudo rm -rf /usr/local/include/Victor/
	@echo "Victor library uninstalled successfully."

clean:
	rm -rf $(OBJ_DIR) $(TARGET_DIR)

.PHONY: all run clean
