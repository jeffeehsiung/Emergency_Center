TITLE_COLOR = \033[32m
RESET_COLOR = \033[0m

# Compiler to use
CXX = g++

# Flags for compiler
CXXFLAGS = -Wall -std=c++20 -Werror -fPIC -fdiagnostics-color=auto

# Source files
SRCS = $(filter-out main.cpp, $(wildcard *.cpp))

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HDRS = $(wildcard headers/*.h)

# Shared library name
LIBRARY = libmylibrary.so

# Executable name
EXEC = main

# Build rules
# from all cpp files, create shared libraries
$(LIBRARY): $(SRCS) $(HDRS)
	@echo "$(TITLE_COLOR)\n***** compiling source files *****$(NO_COLOR)"
	$(CXX) -c $(SRCS) $(CXXFLAGS)
	@echo "$(TITLE_COLOR)\n***** linking shared library *****$(NO_COLOR)"
	g++ -shared -o libmylibrary.so $(OBJS)
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

main: main.cpp $(LIBRARY)
	@echo "$(TITLE_COLOR)\n***** compiling main.cpp *****$(NO_COLOR)"
	$(CXX) -c main.cpp -o main.o $(CXXFLAGS)
	@echo "$(TITLE_COLOR)\n***** linking shared library *****$(NO_COLOR)"
	g++ main.o -L. -lmylibrary -o main -Wall -fsanitize=address -fdiagnostics-color=auto

all: main

run: $(EXEC)
	export LD_LIBRARY_PATH=./:$$LD_LIBRARY_PATH; ./$(EXEC)

# Cleanup object files, executables, and libraries
clean:
	rm -f $(OBJS) $(EXEC) $(LIBRARY) main.o
