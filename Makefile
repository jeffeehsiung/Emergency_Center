FLAGS = -g -std=c11 -Werror -lm $(shell pkg-config --cflags --libs check)

all : main.cpp EmergencyCenter.cpp
	mkdir -p build
	gcc -g -Wall -Werror main.cpp  -o build/EmergencyCenter $(FLAGS)

clean:
	rm -f *.o 
	rm -fr build/


