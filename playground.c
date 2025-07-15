/* playground.c */
#include "playground.h"
#include "map_functions.h" /* is in the level_structure.h */
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>			/*sleep()*/
#include "map_state.h"
#include "files.h"			/* save_level() */

static int map_example[MAP_SIZE][MAP_SIZE] = {
{WALL ,WALL ,WALL ,WALL ,WALL ,WALL ,WALL ,WALL ,WALL ,WALL },
{WALL ,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,WALL },
{WALL ,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,WALL },
{WALL ,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,WALL },
{WALL ,SPACE,ROCK ,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,WALL },
{WALL ,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,WALL },
{WALL ,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,WALL },
{WALL ,SPACE,POCKET,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,WALL},
{WALL ,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,WALL },
{WALL ,WALL ,WALL ,WALL ,WALL ,WALL ,WALL ,WALL ,WALL ,WALL },
};

/* Only shows existing map and user */
void show_map(const int key, struct level *playground)
{
	int my,mx;	/* Screen width (max-y, max-x) */
	int zy,zx;	/* zx/zy - zero pos. Screen position of the map`s left-upper corner */
	int y,x;	/* y/x - position at the map (x+zx coord at a screen) */
	getmaxyx(stdscr,my,mx);
	zy = (my - MAP_SIZE) / 2;
	zx = (mx - MAP_SIZE) / 2;
	if(key == KEY_RESIZE)
		clear();
	for(y = 0; y < MAP_SIZE; y++){
		for(x = 0; x < MAP_SIZE; x++){
			mvprintw(zy + y, zx + x, "%c", (playground -> map)[y][x]);
		}
	}
	/* Show the user */
	mvprintw(zy + (playground -> y), zx + (playground -> x), "%c", '@');
	curs_set(0);
	refresh();
}
 
void play_level(struct level *src_playground)
{
	int key;
	struct level *playground;
	char *win_msg = "YOU WIN!!!";
	int my,mx;

	getmaxyx(stdscr,my,mx);	
	playground = malloc(sizeof(struct level));
	
	/* If level == NULL - play test map */
	if(src_playground != NULL){
		copy_map((*src_playground).map, playground -> map);
		playground -> y = src_playground -> y;
		playground -> x = src_playground -> x;		
	}
	else{
		copy_map(map_example, playground -> map);
		playground -> y = 4;
		playground -> x = 2;
	}
	show_map(KEY_RESIZE, playground);
	while(1){
		key = getch();			/* DRAFT timeout set here */
		switch(key){
			case ERR:
				break;
			case 's':	{
				int i;
				i = save_level("./save_game.camp", 0, playground);
				if (i != 0){
					endwin();
					exit(1);
				}
				key = 'p';
				break;
			}
			case 'l':	{
				int i;
				i = load_level("./save_game.camp", 0, playground);
				if (i != 0)
				{
					endwin();
					exit(1);
				}
				show_map(KEY_RESIZE, playground);
				key = 'p';
				break;
			}
			case 'q':
				return;
			default:	{		/* The decision to play */
				change_map_state(key, (playground -> map), &(playground -> y), &(playground -> x));
				if(check_victory_condition((playground -> map)) == 0)
					{
						clear();
						mvprintw(my/2,mx/2 - 5,"%s",win_msg);
						refresh();
						free(playground);
						sleep(5);
						return;
					}
				else
					show_map(key, playground);
			}
		}
	}
	free(playground); /* DRAFT */
}
