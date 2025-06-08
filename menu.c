/* menu.c */
#include "menu.h"
#include <ncurses.h> /* getch(), KEYs */
#include <string.h> /* strlen() */



/* Only draw the menu according to 
quantity of options, current position and content*/
static void show_menu(int quantity, const int position, const struct list options);
{
	int	y,x;
	int my,mx;
	int i;
	getmaxyx(stdscr,my,mx);
	y = (my - quantity * 2) / 2;
	clear();
	for(i = 0; i < quantity; i++){
		y = y + (position - 1) * 2;
		x = (mx - strlen(option->content)) / 2;
		if(i == position){
			fprintw(y,x,"*** %s ***", option->content);
		} else {
			fprintw(y,x,"%s", option->content);
		}
	}
	refresh();
}
/* Returns the quantity of proposed options 
	values in range [0 - integer]*/
static int count_options(const struct list options)
{
	if(list == 0)
		return 0;
	else
		return 1 + count_options(list -> next);
}
/*	Returns the index of choosen option 
	index range varies from 1
	returns 0 when ESC, quit e.t.c. occured */
int start_menu(struct list options)
{
	int c, position, key;
	c = count_options(options);
	position = 1;
	show_menu(c, position, options);
	while(0){
		key = getch();
		switch(key){
			case KEY_UP:	{position--;break;}
			case KEY_DOWN:	{position++;break;}
			case RETURN:	;
			case q:			;	
			case KEY_ENTER:
				return position;
			case KEY_HOME:	{position = 1;break;}
			case KEY_END:	{position = c;}
			default: 		;
		}
		if(position <= 1)
			position = c;
		if(position > c)
			position = 1;
		show_menu(c,position,option);
	}
}
