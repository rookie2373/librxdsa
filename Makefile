# Makefile for rxdsa C Library

# Compiler and flags
CC       := gcc
CFLAGS   := -Wall -Wextra -Iinclude -g -std=c11 -O2
ARFLAGS  := rcs

# Source and object files
SRC      := $(wildcard src/*.c)
OBJ      := $(SRC:.c=.o)
LIB      := librxdsa.a

# Build examples
EXAMPLES_SRC := $(wildcard examples/*.c)
EXAMPLES     := $(EXAMPLES_SRC:.c=)

# Build tests
TESTS_SRC    := $(wildcard tests/*.c)
TESTS        := $(TESTS_SRC:.c=)

# --- Primary Targets ---

.PHONY: all
all: $(LIB) $(EXAMPLES) $(TESTS)
	@echo "✓ Build complete: $(LIB), $(words $(EXAMPLES)) examples, $(words $(TESTS)) tests"

# Build static library
$(LIB): $(OBJ)
	@echo "📦 Archiving $(words $(OBJ)) objects into $@"
	$(AR) $(ARFLAGS) $@ $^

# Compile library sources
# Note: Added dependency on headers by convention or use -MMD for auto-deps
src/%.o: src/%.c
	@echo "🔨 Compiling $< → $@"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build examples (link against lib)
examples/%: examples/%.c $(LIB)
	@echo "🏗️  Linking example $<"
	$(CC) $(CFLAGS) $< -L. -lrxdsa -o $@

# Build tests (link against lib)
tests/%: tests/%.c $(LIB)
	@echo "🧪 Linking test $<"
	$(CC) $(CFLAGS) $< -L. -lrxdsa -o $@

# --- Execution Targets ---

.PHONY: examples
examples: $(EXAMPLES)
	@echo "▶️  Running $(words $(EXAMPLES)) examples:"
	@for ex in $(EXAMPLES); do \
		echo "  Running $$ex..."; \
		./$$ex || echo "  ⚠️  $$ex failed"; \
	done

.PHONY: tests
tests: $(TESTS)
	@echo "🧪 Running $(words $(TESTS)) tests:"
	@for t in $(TESTS); do \
		echo "  Running $$t..."; \
		./$$t && echo "  ✅ $$t PASSED" || (echo "  ❌ $$t FAILED"; exit 1); \
	done

.PHONY: docs
docs:
	@echo "📚 Generating documentation with Doxygen..."
	doxygen Doxyfile
	@echo "✓ Documentation generated in docs/html and docs/latex"

examples/%.app: examples/%
	@./$<

tests/%.app: tests/%
	@./$<

# --- Maintenance ---

.PHONY: clean
clean:
	@echo "🧹 Cleaning build artifacts..."
	rm -f src/*.o $(LIB) $(EXAMPLES) $(TESTS)
	rm -rf examples/*.dSYM tests/*.dSYM docs/html docs/latex
	@echo "✓ Clean complete"

.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all       - Build library, examples, and tests"
	@echo "  examples  - Build and run all example programs"
	@echo "  tests     - Build and run all unit tests"
	@echo "  clean     - Remove all generated files"
	@echo "  docs      - Generate documentation using Doxygen"
	@echo "  help      - Show this help message"