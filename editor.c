/* editor.c */
#include "map_functions.h"
#include "playground.h"		/* struct level */
#include "editor_files.h"	/* save_e_camp() load_e_camp() */
#include "editor_functions.h" /*show_editor,mv_position,update_edited_map*/
#include "editor.h"
#include <curses.h>			/* echo(), KEY_ codes */
#include <stdlib.h>			/* malloc */
void editor(void)
{
	int key;			/* Pushed button */
	int y_pos, x_pos;	/* Current position on the map*/
	int my, mx;			/* Screen size */
	struct level *play_field;	
	map_type map;		/* Map in the editor */

	play_field = malloc(sizeof(struct level));
	map = play_field -> map;
	play_field -> x = 0;
	play_field -> y = 0;
	y_pos = x_pos = MAP_SIZE / 2;
	getmaxyx(stdscr, my, mx);
	fill_map(map, SPACE);
	show_editor(play_field, my, mx, y_pos, x_pos);
	
	while(1){
		key = getch();
		switch(key) {
			case ERR:	{}
			case 0: {
				break;
			}
			case KEY_RESIZE: {
				getmaxyx(stdscr, my, mx);
				show_editor(play_field, my, mx, y_pos, x_pos);
				key = 0;
				break;
			}
			case 'h':		{}	/* arrows cursor or hjkl*/
			case 'j':		{}
			case 'k':		{}
			case 'l':		{}
			case KEY_UP:	{}
			case KEY_DOWN:	{}
			case KEY_LEFT:	{}
			case KEY_RIGHT:	{
				mv_position(map, key, &y_pos, &x_pos, my, mx);
				show_editor(play_field, my, mx, y_pos, x_pos);
				key = 0;
				break;
			}					
			case 'w':	{}	/* Here are keys for map edition  */
			case 'u':	{}
			case ' ':	{}
			case 'r':	{}
			case 'R':	{}
			case 'o':	{
				update_edited_map(play_field, key, y_pos, x_pos);
				show_editor(play_field, my, mx, y_pos, x_pos);
				key = 0;
				break;
			}
			case 'n':{}			/* DRAFT */
			case 's':{ 
				save_e_camp( play_field );
				show_editor(play_field, my, mx, y_pos, x_pos);
				break;
			}
			case 'g':{			/* load a map */
				load_e_camp( play_field );
				show_editor(play_field, my, mx, y_pos, x_pos);
				break; 			
			}
			case 'q':{
				free(play_field);
				endwin();
				return;}
		}
	}
}
