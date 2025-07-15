/* map_functions.h */
/* The type "map_type" and functions to work with it. */
#ifndef MAP_FUNCTIONS_H
#define MAP_FUNCTIONS_H

#define MAP_SIZE 30
#define WALL 'H'
#define USER '@'
#define SPACE ' '
#define ROCK '#'
#define L_RCK '$'
#define POCKET 'O'

typedef int (*map_type)[MAP_SIZE];

void copy_map(const map_type src, map_type dst);
int extract_usr(map_type map, int *y, int *x);
int check_victory_condition(const map_type map);
int check_map(const map_type map);
void fill_map(map_type map, const int filler);
#endif
