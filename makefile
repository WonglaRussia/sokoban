CC = gcc 
CFLAGS = -c -ggdb -Wall
FFLAGS = -ggdb -Wall
sokoban: main.c change_map_state.o play_map.o
	$(CC) $(FFLAGS) -o $@ -lncurses
change_map_state.o: change_map_state.c change_map_state.h
	$(CC) $(FFLAGS) change_map_state.c -o $@
play_map.o: play_map.c lay_map.h
	$(CC) $(FFLAGS) play_map.c -o $@ -lncurses
