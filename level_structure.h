/* level_structure.h */
#ifndef LEVEL_STRUCTURE_H
#define LEVEL_STRUCTURE_H
#include "map_functions.h"
struct level {
	int x;		/* user position */
	int y;
	int map[MAP_SIZE][MAP_SIZE];
};
#endif
