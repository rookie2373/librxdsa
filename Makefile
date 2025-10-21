# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

# Source and object files
SRC = src/helloworld.c
OBJ = $(SRC:.c=.o)

# Target library and executables
LIB = librxdsa.a
EXAMPLES = examples/library_prompt
TESTS = tests/test_hello_world

# Default target: build library, examples and tests
all: $(LIB) $(EXAMPLES) $(TESTS)

# Build static library from object files
$(LIB): $(OBJ)
	ar rcs $@ $^

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build example executables
examples/%: examples/%.c $(LIB)
	$(CC) $(CFLAGS) $< -L. -lrxdsa -o $@

# Build test executables
tests/%: tests/%.c $(LIB)
	$(CC) $(CFLAGS) $< -L. -lrxdsa -o $@

# Clean build artifacts
clean:
	rm -f src/*.o $(LIB) 
	rm -rf examples/*.o
	rm -rf examples/*.dSYM
	rm -rf tests/*.dSYM
	rm -rf tests/*.o
	find examples -type f ! -name '*.c' -exec rm -f {} +
	find tests -type f ! -name '*.c' -exec rm -f {} +

.PHONY: all clean

# Run all examples
examples: $(EXAMPLES)
	@for example in $(EXAMPLES); do \
		echo "Running $$example..."; \
		./$$example; \
	done

# Run all tests
tests: $(TESTS)
	@for test in $(TESTS); do \
		echo "Running $$test..."; \
		./$$test || exit 1; \
	done
