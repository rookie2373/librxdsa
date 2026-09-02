# Makefile for rxdsa C Library

# === CONFIGURATION ===
CC       ?= gcc
CFLAGS   := -Wall -Wextra -Iinclude -g -std=c11 -O2
ARFLAGS  := rcs

# === INSTALL DIRS ===
PREFIX   ?= /usr/local
EXEC_PREFIX ?= $(PREFIX)
LIBDIR   ?= $(EXEC_PREFIX)/lib
INCLUDEDIR ?= $(PREFIX)/include

# === VARIABLES ===
SRC      := $(wildcard src/*.c)
OBJ      := $(SRC:.c=.o)
LIB      := librxdsa.a

EXAMPLES_SRC := $(wildcard examples/*.c)
EXAMPLES     := $(EXAMPLES_SRC:.c=)

TESTS_SRC    := $(wildcard tests/*.c)
TESTS        := $(TESTS_SRC:.c=)

# === BUILD TARGETS ===

.PHONY: lib
lib: $(LIB) $(TESTS)
	@echo "✓ Build complete: $(LIB), $(words $(TESTS)) tests"

$(LIB): $(OBJ)
	@echo "📦 Archiving $(words $(OBJ)) objects into $@"
	$(AR) $(ARFLAGS) $@ $^

src/%.o: src/%.c
	@echo "🔨 Compiling $< → $@"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

tests/%: tests/%.c $(LIB)
	@echo "🧪 Linking test $<"
	$(CC) $(CFLAGS) $< -L. -lrxdsa -o $@

# === EXECUTION TARGETS ===

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

# === RUN SPECIFIC TARGETS ===

# Shortcuts: make ex:name or make ts:name
ex\:%: $(LIB)
	@if [ ! -f "examples/$*.c" ]; then \
		echo "❌ Example 'examples/$*.c' not found"; \
		exit 1; \
	fi
	@echo "🏗️  Building example: $*"
	@$(CC) $(CFLAGS) examples/$*.c -L. -lrxdsa -o examples/$*
	@echo "▶️  Running example: $*"
	@./examples/$*

ts\:%: $(LIB)
	@if [ ! -f "tests/$*.c" ]; then \
		echo "❌ Test 'tests/$*.c' not found"; \
		exit 1; \
	fi
	@echo "🏗️  Building test: $*"
	@$(CC) $(CFLAGS) tests/$*.c -L. -lrxdsa -o tests/$*
	@echo "🧪 Running test: $*"
	@./tests/$* && echo "✅ $* PASSED" || (echo "❌ $* FAILED"; exit 1)


# === PACMAN INSTALL ===
.PHONY: install
install: $(LIB)
	@echo "🚚 Installing library to $(DESTDIR)$(LIBDIR)"
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(LIB) $(DESTDIR)$(LIBDIR)/

	@echo "🚚 Installing headers to $(DESTDIR)$(INCLUDEDIR)/rxdsa"
	mkdir -p $(DESTDIR)$(INCLUDEDIR)/rxdsa
	cp include/*.h $(DESTDIR)$(INCLUDEDIR)/rxdsa/
	@echo "✓ Installation complete"


# === MAINTENANCE ===

.PHONY: clean
clean: clean-build clean-docs
	@echo "✓ Full clean complete"

.PHONY: clean-build
clean-build:
	@echo "🧹 Cleaning build artifacts..."
	rm -f src/*.o
	rm -f $(LIB)
	rm -f $(EXAMPLES) $(TESTS)
	rm -rf examples/*.dSYM tests/*.dSYM
	@echo "✓ Build artifacts cleaned"

.PHONY: clean-docs
clean-docs:
	@echo "📚 Cleaning documentation..."
	rm -rf docs/html docs/latex
	@echo "✓ Documentation cleaned"

.PHONY: distclean
distclean: clean
	@echo "🧨 Performing distribution clean (aggressive)..."
	find . -name "*.o" -delete
	find . -name "*.a" -delete
	find . -name ".DS_Store" -delete
	@echo "✓ Distribution clean complete"

.PHONY: help
help:
	@echo "Available targets:"
	@echo "  lib         - Build library, examples, and tests"
	@echo "  tests       - Build and run all unit tests"
	@echo "  ex:<name>   - Build and run a specific example"
	@echo "  ts:<name>   - Build and run a specific test"
	@echo "  docs        - Generate documentation using Doxygen"
	@echo ""
	@echo "  clean       - Clean build artifacts and documentation"
	@echo "  clean-build - Clean only build artifacts"
	@echo "  clean-docs  - Clean only documentation"
	@echo "  distclean   - Aggressive clean (removes all generated files)"
	@echo ""
	@echo "  help        - Show this help message"