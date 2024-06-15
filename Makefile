# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Targets
TARGETS = directory practica1 practica2 final

# Source files
SRCS1 = practica_1.c
SRCS2 = practica_2.c

# Object files
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

BUILD_DIRECTORY = build

# Default rule to build all executables
all: $(TARGETS)

directory:
	mkdir -p $(BUILD_DIRECTORY)

# Rule to build main1 executable
practica1: $(OBJS1)
	$(CC) $(CFLAGS) -o $@ $^
	cp $@ $(BUILD_DIRECTORY)

# Rule to build main2 executable
practica2: $(OBJS2)
	$(CC) $(CFLAGS) -o $@ $^
	cp $@ $(BUILD_DIRECTORY)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	cp $@ $(BUILD_DIRECTORY)

final:
	rm -rf $(OBJS1) $(OBJS2) practica1 practica2

# Rule to clean up generated files
clean:
	rm -f $(BUILD_DIRECTORY)

# Phony targets
.PHONY: all clean
