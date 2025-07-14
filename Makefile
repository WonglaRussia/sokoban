CC = gcc 
CFLAGS-C = -c -ggdb -Wall -lcurses -O0
CFLAGS = -c -ggdb -Wall -O0 
FFLAGS = -ggdb -Wall -lcurses -O0
all: sokoban

clean:
	rm -rf *.o

sokoban: main.c playground.o map_state.o map_functions.o menu.o list.o files.o editor.o editor_functions.o editor_functions_support.o editor_files.o editor_files_support.o
	$(CC) $(FFLAGS) main.c playground.o map_state.o map_functions.o menu.o list.o files.o editor.o editor_functions.o editor_functions_support.o editor_files.o editor_files_support.o -o $@
playground.o: playground.c playground.h files.h
	$(CC) $(CFLAGS-C) playground.c -o $@ 
map_functions.o: map_functions.c map_functions.h
	$(CC) $(CFLAGS-C) map_functions.c -o $@
map_state.o: map_state.c map_state.h
	$(CC) $(CFLAGS-C) map_state.c -o $@
list.o: list.c list.h
	$(CC) $(CFLAGS-C) list.c -o $@
menu.o: menu.c menu.h
	$(CC) $(CFLAGS-C) menu.c -o $@
files.o: files.c files.h map_functions.h
	$(CC) $(CFLAGS) files.c -o $@
editor_functions_support.o: editor_functions_support.c editor_functions_support.h
	$(CC) $(CFLAGS-C) editor_functions_support.c -o $@
editor_functions.o: editor_functions.c list.c map_functions.c playground.h
	$(CC) $(CFLAGS-C) editor_functions.c -o $@
editor_files_support.o: editor_files_support.c editor_files_support.h list.o
	$(CC) $(CFLAGS-C) editor_files_support.c  -o $@
editor_files.o: editor_files.c editor_files_support.h 
	$(CC) $(CFLAGS) editor_files.c -o $@
editor.o: editor.c editor_functions.c playground.c map_functions.c editor_files.h
	$(CC) $(CFLAGS-C) editor.c -o $@
