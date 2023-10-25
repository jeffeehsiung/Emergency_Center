# Compiler to use
CXX = g++

# Flags for compiler
CXXFLAGS = -Wall -std=c++20 -I/home/rcw/works/team-a4-ec/

# Source files (all .cpp files in the current directory)
SRCS = $(wildcard *.cpp)

# Executable name
EXEC = $(basename $(SRCS))

# Object files
OBJS = EmergencyCenter.o Component.o Sensor.o SensorGroup.o

# Header files
HDRS = $(wildcard headers/*.h)

# Build rules
# all: $(EXEC)

# $(EXEC): $(OBJS)
#   $(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)
all: $(EXEC)

$(EXEC): $(SRCS)
    $(CXX) $(CXXFLAGS) -o $@ $^

EmergencyCenter.o: EmergencyCenter.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c EmergencyCenter.cpp

Component.o: Component.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Component.cpp

Sensor.o: Sensor.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Sensor.cpp

SensorGroup.o: SensorGroup.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c SensorGroup.cpp

AC.o: AC.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c AC.cpp

CentralDispatch.o: CentralDispatch.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c CentralDispatch.cpp

Email.o: Email.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Email.cpp

FireBrigade.o: FireBrigade.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c FireBrigade.cpp

Gas.o: Gas.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Gas.cpp

GroupAlarm.o: GroupAlarm.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c GroupAlarm.cpp

LeafAlarm.o: LeafAlarm.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c LeafAlarm.cpp

Light.o: Light.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Light.cpp

Motion.o: Motion.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Motion.cpp

Police.o: Police.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Police.cpp

Smoke.o: Smoke.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Smoke.cpp

Sprinkler.o: Sprinkler.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Sprinkler.cpp

Security.o: Security.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c Security.cpp

SMS.o: SMS.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c SMS.cpp


run: $(EXEC)
    ./$(EXEC)

# Cleanup
clean:
    rm -f $(EXEC) $(OBJS)

