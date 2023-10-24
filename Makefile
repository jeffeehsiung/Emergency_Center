# Compiler to use
CXX = g++

# Flags for compiler
CXXFLAGS = -Wall -std=c++20 -I/home/rcw/works/team-a4-ec/

# Executable name
EXEC = my_program

# Object files
OBJS = EmergencyCenter.o Component.o Sensor.o SensorGroup.o

# Header files
HDRS = $(wildcard headers/*.h)

# Build rules
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

EmergencyCenter.o: EmergencyCenter.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c EmergencyCenter.cpp

Component.o: Component.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Component.cpp

Sensor.o: Sensor.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Sensor.cpp

SensorGroup.o: SensorGroup.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c SensorGroup.cpp

run: $(EXEC)
	./$(EXEC)

# Cleanup
clean:
	rm -f $(EXEC) $(OBJS)
