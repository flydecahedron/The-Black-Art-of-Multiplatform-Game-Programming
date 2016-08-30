OBJS = engine.cpp

CC = gcc

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2

OBJ_NAME = engine

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)