COMPILER = gcc
CFLAGS = -pthread -Wall -Wextra -g
COMPILE_PROGRAM = run utilities list threads link_objects 
OBJECTS = run.o utilities.o list.o threads.o
CLIENT_EXE = quicksort

all: $(COMPILE_PROGRAM)

link_objects: 
	$(COMPILER) $(CFLAGS) $(OBJECTS) -o $(CLIENT_EXE)

run: run.c utilities.h list.h threads.h 
	$(COMPILER) $(CFLAGS) run.c -c -o run.o

utilities: utilities.c utilities.h list.h
	$(COMPILER) $(CFLAGS) utilities.c -c -o utilities.o

list: list.c list.h 
	$(COMPILER) $(CFLAGS) list.c -c -o list.o

threads: threads.c threads.h list.h
	$(COMPILER) $(CFLAGS) threads.c -c -o threads.o

clean: 
	-rm -r $(OBJECTS) 

valgrind:
	valgrind --tool=memcheck  --leak-check=full --show-reachable=yes ./quicksort dictionary.txt
tar:
	@tar -cpzf multi_threaded_qs.tgz*

