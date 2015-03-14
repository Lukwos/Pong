#-- program name, sources and obj --
TARGET=Pong
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

#-- compiler/linker settings --
CC=g++
CCFLAGS=-W -Wall -pedantic -g -Wno-long-long
IFLAGS=-I./include
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

#-- main target to obtain --
all : $(TARGET)

#-- linker command to produce the executable file --
$(TARGET) : $(OBJ)
	@echo Linking $@ ...
	$(CC) $^ -o $@ $(LDFLAGS)
	@echo

#-- compiler command for every source file --
%.o : %.cpp
	@echo Compiling $< ....
	$(CC) -c $< $(IFLAGS) -o $@ $(CCFLAGS)
	@echo

.PHONY: clean

#-- system-specific command to remove those files --
clean :
	@echo Cleaning...
	rm -f $(OBJ) $(TARGET) src/*~ include/*~ *~
	@echo

run :
	./$(TARGET)

