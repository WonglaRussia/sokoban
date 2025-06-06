/* change_map_state.c */
#include <ncurses.h>	/* KEY_DOWN KEY_UP et.c. */
#include "play_map.h"  	/* MAP_SIZE map_type, definition of map objects WALL,ROCK e.t.c */
#include "change_map_state.h"
/* Changes the map state according to...
key input (key arrows) and x_position y_postion (user coordinates) */
void change_map_state(const int key, map_type map, int *y_position, int *x_position)
{
	/*Direction of the user`s movement [-1,0,+1]*/
	int dy,dx; 					
	/*Objects next in direction of mevement and after it*/
	int next_obj, after_next_obj;
	dy = dx = 0;
	switch(key){
		case KEY_UP:	{dy--; break;}
		case KEY_DOWN:	{dy++; break;}
		case KEY_RIGHT:	{dx++; break;}
		case KEY_LEFT:	{dx--; break;}
	}
	next_obj = map[*y_position + dy][*x_position + dx];
	after_next_obj = map[*y_position + 2*dy][*x_position + 2*dx];
/* Change the map according to direction and current user position*/
/* DRAFT add getting user possition, add checking the tile under the user*/
	/*There is no a positive direction*/
	if(dx && dy)										
		return;
	/*Next to the wall*/
	if(next_obj == WALL){
		return;
	}
	/*The next is a POCKET*/
	if (next_obj == POCKET || next_obj == SPACE){
	/*Just move user position*/	
		*y_position += dy;
		*x_position += dx;
		return;
	}
	/*The next is a ROCK*/
	if(next_obj == ROCK || next_obj == L_RCK){
		/*After the ROCK neither SPACE nor POCKET*/
		if(!(after_next_obj == SPACE || after_next_obj == POCKET))
			return;
		/*After the ROCK is SPACE or POCKET*/
		else {
			/* Change user position. */
			/* !From here position is shifted! */
			*y_position += dy;
			*x_position += dx;
			if(next_obj == ROCK)
			/* Remove the rock */
				map[*y_position][*x_position] = SPACE;
			else
			/* not rock == rock was the pocket.*/
				map[*y_position][*x_position] = POCKET;
			if(after_next_obj == SPACE) 
			/* Place the rock in the after the next position ... */
				map[*y_position + dy][*x_position + dx] = ROCK;
			else
			/* ... or put the rock in the pocket */
				map[*y_position + dy][*x_position + dx] = L_RCK;
			return;
		}
	}
}