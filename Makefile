COMPILER = gcc
CFLAGS = -Wall -Wextra -g
COMPILE_PROGRAM = run utilities list link_objects
OBJECTS = run.o utilities.o list.o
CLIENT_EXE = quicksort

all: $(COMPILE_PROGRAM)

link_objects: 
	$(COMPILER) $(CFLAGS) $(OBJECTS) -o $(CLIENT_EXE)

run: run.c utilities.h list.h
	$(COMPILER) $(CFLAGS) run.c -c -o run.o

utilities: utilities.c utilities.h 
	$(COMPILER) $(CFLAGS) utilities.c -c -o utilities.o

list: list.c list.h 
	$(COMPILER) $(CFLAGS) list.c -c -o list.o

clean: 
	-rm -r $(OBJECTS) 

valgrind:
	valgrind --tool=memcheck  --leak-check=full --show-reachable=yes ./quicksort
tar:
	@tar -cpzf multi_threaded_qs.tgz*
            
