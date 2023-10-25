# Compiler to use
CXX = g++

# Flags for compiler
CXXFLAGS = -Wall -std=c++20

# Source files (all .cpp files in the current directory)
SRCS = $(wildcard *.cpp)

# Executable name
EXEC = $(basename $(SRCS))

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HDRS = $(wildcard headers/*.h)

# Build rules
all: $(EXEC)

$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

EmergencyCenter: EmergencyCenter.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c EmergencyCenter.cpp

Component: Component.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Component.cpp

Sensor: Sensor.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Sensor.cpp

SensorGroup: SensorGroup.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c SensorGroup.cpp

# Rest of your object files and dependencies...
AC: AC.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c AC.cpp

CentralDispatch: CentralDispatch.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c CentralDispatch.cpp

Email: Email.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Email.cpp

FireBrigade: FireBrigade.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c FireBrigade.cpp

Gas: Gas.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Gas.cpp

GroupAlarm: GroupAlarm.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c GroupAlarm.cpp

LeafAlarm: LeafAlarm.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c LeafAlarm.cpp

Light: Light.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Light.cpp

Motion: Motion.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Motion.cpp

Police: Police.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Police.cpp

Security: Security.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Security.cpp

Smoke: Smoke.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Smoke.cpp

SMS: SMS.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c SMS.cpp

Sprinkler: Sprinkler.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c Sprinkler.cpp

run: $(EXEC)
	./$(EXEC)

# Cleanup
clean:
	rm -f $(EXEC) $(OBJS)
