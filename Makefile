CC = gcc
ASM = nasm
CFLAGS = -m32 -g -Wall
ASMFLAGS = -f elf32 -g -w+all
OUT = bin/encoder
OBJDIR = bin
SRCDIR = src

# Targets
all: clean compilation linkFile

# Compile object files
compilation: $(OBJDIR)/main.o $(OBJDIR)/numbers.o $(OBJDIR)/add.o

# Link object files to create the final executable
linkFile: $(OBJDIR)/main.o $(OBJDIR)/numbers.o $(OBJDIR)/add.o
	$(CC) $(CFLAGS) -m32 -o $(OUT) $(OBJDIR)/main.o $(OBJDIR)/numbers.o $(OBJDIR)/add.o

# Compile src/main.c to bin/main.o
$(OBJDIR)/main.o: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile src/numbers.c to bin/numbers.o
$(OBJDIR)/numbers.o: $(SRCDIR)/numbers.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble src/add.s to bin/add.o
$(OBJDIR)/add.o: $(SRCDIR)/add.s
	$(ASM) $(ASMFLAGS) $< -o $@

# Clean up
clean:
	rm -f $(OBJDIR)/*