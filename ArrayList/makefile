CC=g++
CFLAGS=-I $(LIBS)

MKBIN = mkdir $(BIN)
MKBUILD = mkdir $(BUILD)

BIN = bin/
BUILD = build/
LIBS = include/
SRC = src/

_DEPS=\
	ArrayList.h \
	ArrayList.tpp
DEPS = $(patsubst %,$(LIBS)%,$(_DEPS))

_OBJ=\
	main.o \
	test.o
OBJ = $(patsubst %,$(BUILD)%,$(_OBJ))

main: mkdir $(OBJ)
	$(CC) $(OBJ) -o $(addprefix $(BIN),$@)

$(BUILD)%.o: $(SRC)%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

mkdir:
	$(RM) -r $(BIN)
	$(RM) -r $(BUILD)
	$(MKBIN)
	$(MKBUILD)

clean:
	$(RM) -r $(BUILD)
