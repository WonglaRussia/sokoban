/* main.c */
#include <curses.h>
#include <stdlib.h>			/* exit(0) */
#include "map_functions.h" 	/* defines WALL,SPACE etc */
#include "playground.h"		/* play_map() */
#include "list.h"
#include "menu.h"
#include "editor.h"			/* editor() */
/* DRAFT reallocate it in play functions while speed is changing */
enum {DELAY_DURATION = 300};
enum {QUICK_PLAY = 1, EDITOR=2, EXIT = 3};
int main()
{
	struct list *main_menu;
	int desition = 1;
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,1);
	timeout(300);

	fill_the_list(&main_menu,"Quick play", "Editor", "Exit", NULL);
	while(1){
		desition = play_menu(main_menu);
		switch(desition){
			case QUICK_PLAY: {
				play_level(NULL);	/* NULL makes functions to play example */
				break;
			}
			case EDITOR: {
				editor();
				break;
			}
			case EXIT:{
				endwin();
				exit(0);
			}
		}
	}
	endwin();
	return 0;
}
