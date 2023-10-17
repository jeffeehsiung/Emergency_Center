# Compiler to use
CXX = g++

# Flags for compiler
CXXFLAGS = -Wall -std=c++17
# -I/home/rcw/cpp_tests/AdvancedProgrammingTechniques

# Executable name
EXEC = my_program

# Object files
OBJS = main.o Box.o truckload.o thoughpack.o

# Header files
HDRS = Box.h truckload.h thoughpack.h

# Build rules

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $<

run: $(EXEC)
	./$(EXEC)

# Cleanup
clean:
	rm -f $(EXEC) $(OBJS)
