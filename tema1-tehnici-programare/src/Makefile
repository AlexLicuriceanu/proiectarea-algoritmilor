OBJS	= main.o Solution.o
SOURCE	= main.cpp Solution.cpp
HEADER	= Solution.h
OUT	= tema
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Solution.o: Solution.cpp
	$(CC) $(FLAGS) Solution.cpp 

clean:
	rm -rf $(OBJS) $(OUT) ./**/test.out