# Compiler to use
CXX = g++

# Flags for compiler
CXXFLAGS = -Wall -std=c++20 -I/home/rcw/works/team-a4-ec/

# Executable name
EXEC = my_program

# Object files
OBJS = EmergencyCenter.o Component.o

# Header files
HDRS = headers/EmergencyCenter.h headers/Component.h headers/SensorStrategy.h

# Build rules
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

EmergencyCenter.o: EmergencyCenter.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c EmergencyCenter.cpp

Component.o: Component.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Component.cpp

run: $(EXEC)
	./$(EXEC)

# Cleanup
clean:
	rm -f $(EXEC) $(OBJS)
