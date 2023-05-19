OBJS	= checker.o task1.o
SOURCE	= checker.cpp task1.cpp
HEADER	= util.h
OUT	= checker
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

checker.o: checker.cpp
	$(CC) $(FLAGS) checker.cpp 

task1.o: task1.cpp
	$(CC) $(FLAGS) task1.cpp 


clean:
	rm -f $(OBJS) $(OUT)
