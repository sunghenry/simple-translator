CC = g++
CFLAGS = -g -Wall -std=c++11 -Iinclude
LIBS =
TARGET = run

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
_DEPS = base.hpp hash.hpp list.hpp
_OBJS = main.o base.o hash.o list.o

DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
