/* test_menu.c */
#include <curses.h>
#include <unistd.h>
#include "list.h"
#include "menu.h"
#define TEST
#ifdef TEST
	#include <stdio.h>
#endif

int main()
{
	struct list *options;
	
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,1);
	timeout(300);
#ifdef TEST
	printf("Main started\n");
#endif
	fill_the_list(&options, "Option one", "Option two", "Option three", NULL);
	play_menu(options);
	sleep(300);
	endwin();
	return 0;
}