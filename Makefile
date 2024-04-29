# Specify the compiler
COMPILER = g++

# Specify where are the header file
INCLUDE_PATH = -Iinclude

# Specify library file
LIBRARY_PATH = -Llib

# Linker flag for SDL2
LINKER_FLAGS = -lSDl2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# Compiler flag?
COMPILER_FLAGS = -lmingw32 -g

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%,$(SRCS))

all:
	for file in ${OBJS} ; do \
		echo "Creating $$file.o" ; \
		$(COMPILER) $(INCLUDE_PATH) $(LIBRARY_PATH) -c $$file.cpp $(COMPILER_FLAGS); \
		echo "Created $$file.o"; \
	done 
	$(COMPILER) $(INCLUDE_PATH) $(LIBRARY_PATH) -o main *.o $(COMPILER_FLAGS) $(LINKER_FLAGS)