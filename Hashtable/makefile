CC=g++
TESTCC=cxxtestgen
CFLAGS=-I $(LIBS)
TESTFLAGS=--error-printer

MKBIN = mkdir $(BIN)
MKBUILD = mkdir $(BUILD)

BIN = bin/
BUILD = build/
LIBS = include/
SRC = src/
TEST = test/

_DEPS=\
	HashTable.h \
	HashTable.tpp
DEPS = $(patsubst %,$(LIBS)%,$(_DEPS))

_OBJ=\
	main.o
OBJ = $(patsubst %,$(BUILD)%,$(_OBJ))

_CXX=\
	TestHashTable.cpp
CXX = $(patsubst %,$(BUILD)%,$(_CXX))

MAIN = main
MAIN_TEST = test

default: mkdir $(OBJ)
	$(CC) $(OBJ) -o $(addprefix $(BIN),$(MAIN))

$(BUILD)%.o: $(SRC)%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

$(MAIN_TEST): $(CXX)
	$(CC) $^ -o $(addprefix $(BIN),$@) $(CFLAGS)

$(BUILD)%.cpp: $(TEST)%.h
	$(TESTCC) $(TESTFLAGS) $< -o $@

run:
	./$(BIN)$(MAIN)

runtest:
	./$(BIN)$(MAIN_TEST)

mkdir:
	$(RM) -r $(BIN)
	$(RM) -r $(BUILD)
	$(MKBIN)
	$(MKBUILD)

clean:
	$(RM) -r $(BUILD)
