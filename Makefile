# Compiler to use
CXX = g++

# Flags for compiler
CXXFLAGS = -Wall -g -std=c++20 
# -I/home/rcw/cpp_tests/AdvancedProgrammingTechniques

# Header files
HDRS = $(wildcard *.h)

# Source files (all .cpp files in the current directory)
SRCS = $(wildcard *.cpp)

# Output Executable name
EXEC = $(basename $(SRCS))$

# Build rules

all: $(EXEC)

$(EXEC): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build main.cpp
main: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

# Cleanup
clean:
	rm -f $(EXEC) *.o *~
