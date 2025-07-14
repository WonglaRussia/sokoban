/* playground.h */
#include "map_functions.h"
#ifndef PLAYGROUND_H
#define PLAYGROUND_H
struct level {
	int x;		/* user position */
	int y;
	int map[MAP_SIZE][MAP_SIZE];
};
void show_map(const int key, struct level *playground);
void play_level(struct level *src_playground);
#endif