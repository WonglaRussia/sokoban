/* editor_functions.c */
#include "map_functions.h"
#include "playground.h" /* struct level */
#include "editor_functions.h"
#include "editor_functions_support.h" /* show_edited_map() fringe_area() ...
															... defines SIETE_BAR_WIDTH e.t.c		 */
#include <curses.h>	/* KEY_ codes, resresh(), clear */
//#include <stdlib.h> /* free() */

void show_editor(struct level *play_ground, const int my, const int mx, const int pos_y, const int  pos_x)
{
	int map_position_y, map_position_x;
	clear();
	map_position_y = (my  - MAP_SIZE) / 2;
	map_position_x = get_map_position(mx);
	if(!map_position_x){
		mvprintw(1, 1, "Enlarge the screen.");
		refresh();
		return;
	} else { 
		fringe_area(map_position_y, map_position_x, MAP_SIZE, MAP_SIZE);
		show_edited_map(play_ground, map_position_y, map_position_x);
	 	show_side_bar(map_position_y, mx / 2);
		if(play_ground -> y && play_ground -> x )
			mvaddch(play_ground -> y + map_position_y, play_ground -> x + map_position_x, '@');
	/* show cursor position */
		move(pos_y + map_position_y, pos_x + map_position_x);
		addch('#');
		refresh();
	}
}

/*	Change the position limited by the map size */
void mv_position(map_type map, const int key, int *position_y, int *position_x, int my, int mx)
{
	int map_position_y, map_position_x;
	map_position_x = get_map_position(mx);
	map_position_y = (my - MAP_SIZE) / 2;
	move(map_position_y + *position_y, map_position_x + *position_x);
	addch(map[*position_y][*position_x]);
	switch(key) {
		case 'h':{}
		case KEY_LEFT:{
			(*position_x)--;
			break;	
		}
		case 'l':{}
		case KEY_RIGHT:{
			(*position_x)++;
			break;
		}
		case 'k':{}
		case KEY_UP:{
			(*position_y)--;
			break;
		}
		case 'j':{}
		case KEY_DOWN:{
			(*position_y)++;
			break;
		default: 
			break;
		}
	}
	chk_pos(position_y);
	chk_pos(position_x);	
	move(map_position_y + *position_y, map_position_x + *position_x);
	addch('#');
	return;
}
 /* Put objects to the map according your choise (key button) */
void update_edited_map(struct level *play_field, const int key, const int position_y, const int position_x)
{ /* w - wall, r - rock, R locked rock, o - hole */
	if(key == 'w' || key == ' '	|| key == 'R' || key == 'r' || key == 'o'){
		switch(key) {
			case 'w':{
				(play_field -> map)[position_y][position_x] = WALL;	
				return;
			}
			case ' ':{
				(play_field -> map)[position_y][position_x] = SPACE;	
				return;
			}
			case 'r':{
				(play_field -> map)[position_y][position_x] = ROCK;	
				return;
			}
			case 'R':{
				(play_field -> map)[position_y][position_x] = L_RCK;	
				return;
			}
			case 'o':{
				(play_field -> map)[position_y][position_x] = POCKET;	
				return;
			}
		}
	}
	if(key == 'u'){	/* user position is not on the map */
		play_field -> y = position_y;
		play_field -> x = position_x;
		return;
	}
}
/*void save_map(map_typ map)
void load_map(map_type map)*/
