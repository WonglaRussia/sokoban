/* play_map.h */

/* There must be all types and functions to play the map. */

#ifndef PLAY_MAP_H
#define PLAY_MAP_H

#define MAP_SIZE 6
#define WALL 'X'
#define USER '@'
#define SPACE ' '
#define ROCK '#'
#define L_RCK '$'
#define POCKET 'O'

typedef int (*map_type)[MAP_SIZE];
void play_map(const map_type map);

#endif