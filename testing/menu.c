/* menu.c */
#include "list.h" 		/* struct list, count items(), et.c. */
#include "menu.h"
#include <ncurses.h> 	/* getch(), KEYs */
#include <string.h> 	/* strlen() */
#include <unistd.h>

/* Only draw the menu according to 
quantity of options, current position and content*/
static void show_menu(const int position, struct list *options)
{
	int	y,x;
	int my,mx;				/* max of screen dimentions */
	int i;
	int quantity;
	struct list *ptr;
	
	ptr = options;
	quantity = count_items(options);
	getmaxyx(stdscr,my,mx);
	my = (my - quantity * 2) / 2;
	clear();
	for(i = 1; ptr != NULL; i++){
		y = my + (i - 1) * 2;
		x = (mx - strlen(ptr->content)) / 2;
		if(i == position){
			mvprintw(y,x - 4,"*** %s ***", ptr->content);
		} else {
			mvprintw(y,x,"%s", ptr->content);
		}
		ptr = ptr->next;
	}
	curs_set(0);
	refresh();
}
/*	Returns the index of choosen option 
	index range varies from 1 to int
	returns 0 when ESC, quit e.t.c. occured */
int play_menu(struct list *options)
{
	int c, position, key; /*  */
	c = count_items(options);
	position = 1;
	show_menu(position, options);
	while(1){
		key = getch();
		switch(key){
			case ERR:		{break;}
			case KEY_UP:	{position--;break;}
			case KEY_DOWN:	{position++;break;}
			case KEY_HOME:	{position = 1;break;}
			case KEY_END:	{position = c;}
			case 'q':		{return 0;}
			case KEY_RIGHT: {;}
			case KEY_ENTER:	{return position;}  		/*  */
			default: 		;
		}
		if(position < 1)
			position = c;
		if(position > c)
			position = 1;
		show_menu(position,options);
	}
	return 0;
}

