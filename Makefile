# Makefile for rxdsa C Library
# Builds static library, examples, and tests from src/, examples/, and tests/ directories.
# Supports: make all, make clean, make examples (build+run), make tests (build+run)

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Iinclude -g -std=c11 -O2
ARFLAGS := rcs

# Source and object files (dynamic via wildcard)
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,src/%.o,$(SRC))
LIB := librxdsa.a

# Examples and tests (dynamic via wildcard)
EXAMPLES_SRC := $(wildcard examples/*.c)
EXAMPLES := $(patsubst examples/%.c,examples/%,$(EXAMPLES_SRC))
TESTS_SRC := $(wildcard tests/*.c)
TESTS := $(patsubst tests/%.c,tests/%,$(TESTS_SRC))

# Default target: build everything
.PHONY: all
all: $(LIB) $(EXAMPLES) $(TESTS)
	@echo "✓ Build complete: $(LIB), $(words $(EXAMPLES)) examples, $(words $(TESTS)) tests"

# Build static library
$(LIB): $(OBJ)
	@echo "📦 Archiving $(words $(OBJ)) objects into $@"
	$(AR) $(ARFLAGS) $@ $^

# Compile library sources
src/%.o: src/%.c
	@echo "🔨 Compiling $< → $@"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build examples (link against lib)
examples/%: examples/%.c $(LIB)
	@echo "🏗️  Linking example $< → $@"
	$(CC) $(CFLAGS) $< -L. -lrxdsa -o $@

# Build tests (link against lib)
tests/%: tests/%.c $(LIB)
	@echo "🧪 Linking test $< → $@"
	$(CC) $(CFLAGS) $< -L. -lrxdsa -o $@

# Run all examples (build if needed)
.PHONY: examples
examples: $(EXAMPLES)
	@echo "▶️  Running $(words $(EXAMPLES)) examples:"
	@for ex in $(EXAMPLES); do \
		echo "  $$ex:"; \
		./$$ex || echo "  ⚠️  $$ex failed"; \
	done

# Run all tests (build if needed, fail fast)
.PHONY: tests
tests: $(TESTS)
	@echo "🧪 Running $(words $(TESTS)) tests:"
	@for t in $(TESTS); do \
		echo "  $$t:"; \
		./$$t || (echo "  ❌ $$t FAILED"; exit 1); \
	done

# Clean all artifacts
.PHONY: clean
clean:
	@echo "🧹 Cleaning build artifacts..."
	rm -f src/*.o $(LIB)
	rm -f $(EXAMPLES) $(TESTS)
	rm -rf examples/*.o examples/*.dSYM tests/*.o tests/*.dSYM
	rm -rf docs/html
	rm -rf docs/latex
	@echo "✓ Clean complete"

# Doxygen document generation
.PHONY: docs
docs:
	@echo "Building documentation..."
	doxygen Doxyfile

# Help
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all       - Build library, examples, tests"
	@echo "  examples  - Build and run all examples"
	@echo "  tests     - Build and run all tests"
	@echo "  clean     - Remove build artifacts"
	@echo "  help      - Show this help"