/* main.c */

#include <ncurses.h>
#include <unistd.h>	/* sleep */
#include <stdlib.h> /* malloc */

#define WALL '#'
#define USER '@'
#define SPAC ' '
#define MAP_SIZE 6

int map_example[MAP_SIZE][MAP_SIZE] = {
{'#','#','#','#','#','#'},
{'#',' ','@',' ',' ','#'},
{'#',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ','#'},
{'#','#','#','#','#','#'},
};

typedef int (*map_type)[MAP_SIZE];

enum {DELAY_DURATION = 100};

void show_map(const map_type map)
{
	int shift;
	int y,x,my,mx,zy,zx;

	getmaxyx(stdscr,my,mx);
	zy = (my - MAP_SIZE) / 2;
	zx = (mx - MAP_SIZE) / 2;
	shift = 0; 
	for(y = 0; y < MAP_SIZE; y++){
		for(x = 0; x < MAP_SIZE; x++){
			mvprintw(zy+y,zx+x,"%c", map[y][x]);
			shift += sizeof(int);
		}
	}
	curs_set(0);
	refresh();
}

void copy_map(const map_type src, map_type dst)
{
	int y,x;
	for(y = 0; y < MAP_SIZE; y++)
		for(x = 0; x < MAP_SIZE; x++){
			 dst[y][x] = src[y][x];
		}
}

void play_map(const map_type map)
{
	void *playground;
	playground = malloc(sizeof(map_example));
	copy_map(map,playground);
	show_map(playground);
	sleep(1);
	free(playground);
}



int main(int argn, char **argv)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,1);
	timeout(DELAY_DURATION);	
	play_map(map_example);
	endwin();
	return 0;
}
