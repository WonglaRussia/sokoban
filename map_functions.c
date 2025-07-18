/* map_functions.c */
#include "map_functions.h" /*MAP_SIZE map_type, definition of map objects WALL,ROCK e.t.c */
#include <ncurses.h>
#include <unistd.h>		/* sleep */
#include <stdlib.h>		/* malloc */

/* Stash the map to the memory */
void copy_map(const map_type src, map_type dst)
{
	int y,x;
	if (check_map(src) == 1){
		endwin();
		exit (1);
	}
	for(y = 0; y < MAP_SIZE; y++)
		for(x = 0; x < MAP_SIZE; x++){
			 dst[y][x] = src[y][x];
		}
}
/* Finds coordinates of the user on the map,
	sets SPACE at the user`s place.
   Returns not 0 if there is no user */
int extract_usr(map_type map, int *y, int *x)
{
	int cy,cx; /* Count rows and columns */
	for(cy = 0; cy < MAP_SIZE; cy++){
		for(cx =0; cx < MAP_SIZE; cx++){
				if(map[cy][cx] != '@')
					continue;
				else {
					*y = cy;
					*x = cx;
/* User`s coordinates are deteminated by variables not map */
					map[cy][cx] = ' ';
					return 0;
				}
		}
	}
	return 1; /* The map does not contain user */
}
/* Check the map for completion of the level 
	if level completed return 0 else 1 */
int check_victory_condition(const map_type map)
{
	int cy,cx;
	int pockets, rocks;
	pockets = rocks = 0;
	for(cy = 0; cy < MAP_SIZE; cy++)
		for(cx =0; cx < MAP_SIZE; cx++)
				switch (map[cy][cx]){
					case POCKET:{
						pockets++; 
						break;
					}
					case ROCK:{
						rocks++;
						break;
					}
				}
	if(!pockets || !rocks)
		/* All rocks are in pockets (rocks == 0)
		OR all pockets are filled (pockets == 0) 
		for the case if pockets != rocks */
		return 0;
	else
		return 1;
}
/* Returns 1 if any cell
		value is out of array of definitions */
int check_map(const map_type map)
{
	int x,y,value;
	for(y = 0; y < MAP_SIZE; y++)
		for(x = 0; x < MAP_SIZE; x++){
			value = map[y][x];
			switch (value){
				case WALL: break;
				case USER: break;
				case SPACE: break;
				case ROCK: break;
				case L_RCK: break;
				case POCKET: break;
				default: return 1;
			}
		}
	return 0;
}
void fill_map(map_type map, const int filler)
{
	int y, x;
	for(y = 0; y < MAP_SIZE; y++)
		for(x = 0; x < MAP_SIZE; x++){
			map[y][x] = filler;
	}
}
