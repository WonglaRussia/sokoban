CC = gcc 
CFLAGS = -c -ggdb -Wall -lcurses
FFLAGS = -ggdb -Wall -lcurses
test_menu_1: test_menu.c list.o menu.o
	$(CC) $(FFLAGS) test_menu.c list.o menu.o -o $@
list.o: list.c
	$(CC) $(CFLAGS) list.c -o $@ 
menu.o: menu.c
	$(CC) $(CFLAGS) menu.c -o $@