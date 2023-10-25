TITLE_COLOR = \033[32m
RESET_COLOR = \033[0m

# Compiler to use
CXX = g++

# Flags for compiler
CXXFLAGS = -Wall -std=c++20 -Werror -fPIC -fdiagnostics-color=auto

# Source files (all .cpp files in the current directory)
SRCS = AC.cpp CentralDispatch.cpp Component.cpp Email.cpp EmergencyCenter.cpp FireBrigade.cpp Gas.o GroupAlarm.cpp LeafAlarm.cpp Light.cpp Motion.cpp Police.cpp Security.cpp Sensor.cpp SensorGroup.cpp Smoke.cpp SMS.cpp Sprinkler.cpp

# Executable name
EXEC = $(basename $(SRCS))

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HDRS = $(wildcard headers/*.h)

# Build rules
all: main

main: main.cpp libmylibrary.so
	@echo "$(TITLE_COLOR)\n***** compiling main.cpp *****$(NO_COLOR)"
	g++ -c main.cpp -Wall -std=c++20 -Werror -o main.o -fdiagnostics-color=auto
	@echo "$(TITLE_COLOR)\n***** linking shared library *****$(NO_COLOR)"
	g++ main.o -L. -lmylibrary -o main -Wall -fdiagnostics-color=auto

# if you only want to compile the library
libEmergencyCenter: libmylibrary.so

# from all cpp files, create shared libraries
libmylibrary.so: AC.cpp CentralDispatch.cpp Component.cpp Email.cpp EmergencyCenter.cpp FireBrigade.cpp Gas.o GroupAlarm.cpp LeafAlarm.cpp Light.cpp Motion.cpp Police.cpp Security.cpp Sensor.cpp SensorGroup.cpp Smoke.cpp SMS.cpp Sprinkler.cpp $(HDRS)
	@echo "$(TITLE_COLOR)\n***** compiling source files *****$(NO_COLOR)"
	$(CXX) $(CXXFLAGS) -c AC.cpp -o AC.o
	$(CXX) $(CXXFLAGS) -c CentralDispatch.cpp -o CentralDispatch.o
	$(CXX) $(CXXFLAGS) -c Component.cpp -o Component.o
	$(CXX) $(CXXFLAGS) -c Email.cpp -o Email.o
	$(CXX) $(CXXFLAGS) -c EmergencyCenter.cpp -o EmergencyCenter.o
	$(CXX) $(CXXFLAGS) -c FireBrigade.cpp -o FireBrigade.o
	$(CXX) $(CXXFLAGS) -c Gas.cpp -o Gas.o
	$(CXX) $(CXXFLAGS) -c GroupAlarm.cpp -o GroupAlarm.o
	$(CXX) $(CXXFLAGS) -c LeafAlarm.cpp -o LeafAlarm.o
	$(CXX) $(CXXFLAGS) -c Light.cpp -o Light.o
	$(CXX) $(CXXFLAGS) -c Motion.cpp -o Motion.o
	$(CXX) $(CXXFLAGS) -c Police.cpp -o Police.o
	$(CXX) $(CXXFLAGS) -c Security.cpp -o Security.o
	$(CXX) $(CXXFLAGS) -c Sensor.cpp -o Sensor.o
	$(CXX) $(CXXFLAGS) -c SensorGroup.cpp -o SensorGroup.o
	$(CXX) $(CXXFLAGS) -c Smoke.cpp -o Smoke.o
	$(CXX) $(CXXFLAGS) -c SMS.cpp -o SMS.o
	$(CXX) $(CXXFLAGS) -c Sprinkler.cpp -o Sprinkler.o
	@echo "$(TITLE_COLOR)\n***** linking shared library *****$(NO_COLOR)"
	g++ -shared -o libmylibrary.so AC.o CentralDispatch.o Component.o Email.o EmergencyCenter.o FireBrigade.o Gas.o GroupAlarm.o LeafAlarm.o Light.o Motion.o Police.o Security.o Sensor.o SensorGroup.o Smoke.o SMS.o Sprinkler.o

EmergencyCenter: EmergencyCenter.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c EmergencyCenter.cpp -o EmergencyCenter.o
	g++ -shared -o libEmergencyCenter.so EmergencyCenter.o

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

# all: $(EXEC)

# $(EXEC): $(SRCS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# all: $(LIBRARY)

# $(LIBRARY): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -shared -o $@ $^

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

# use the generated shared library in the main program
test: main.cpp libmylibrary.so
	@echo "$(TITLE_COLOR)\n***** testing shared library *****$(NO_COLOR)"
	g++ -c main.cpp -Wall -std=c++20 -Werror -o main.o -fdiagnostics-color=auto
	@echo "$(TITLE_COLOR)\n***** linking shared library *****$(NO_COLOR)"
	g++ main.o -L. -lmylibrary -o test -fdiagnostics-color=auto

# Cleanup object files, executables, and libraries
clean:
	rm -f $(OBJS) $(EXEC) $(LIBRARY)
