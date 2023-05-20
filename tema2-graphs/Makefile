OBJS	= checker.o task1.o task2.o task3.o
SOURCE	= checker.cpp task1.cpp task2.cpp task3.cpp
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

task2.o: task2.cpp
	$(CC) $(FLAGS) task2.cpp

task3.o: task3.cpp
	$(CC) $(FLAGS) task3.cpp

clean:
	rm -f $(OBJS) $(OUT)
