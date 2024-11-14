# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Targets
TARGET = encoder
SRC = encoder.c

# Default target to build the program
all: $(TARGET)

# Build the executable from the source file
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	rm -f $(TARGET) *.o

# Debug target - with debugging mode enabled
debug: CFLAGS += -DDEBUG
debug: $(TARGET)

# Run the program with debugging mode on
run-debug: debug
	./$(TARGET) +D

# Run the program normally
run:
	./$(TARGET)

# Run the program with an input and output file (example use case)
run-file:
	./$(TARGET) -iinput.txt -ooutput.txt

# PHONY targets for 'make clean' and other commands
.PHONY: all clean debug run run-debug run-file
