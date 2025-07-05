 /* sup_ed_functions.c */
#include "list.h"
#include "map_functions.h"
#include "playground.h"
#include "sup_ed_functions.h"
#include <curses.h>
#include <stdlib.h>

	/* Fringe an area according to coordinates, height, width */
	/* Coordinates - left upper conner of the aria  */
	/* Shows the map and the side bar
		 If there is not anough space for the side bar. It prints only a map.
		 If there is not anough space for a map It prints a warning. */
void fringe_area(const int coord_y, const int coord_x, const int height, const int width)
{
	int y,x;
	y = coord_y - 1;
	x = coord_x - 1;
	for(int iy = y ; iy <= y + width + 1; iy++)
		for(int ix = x ; ix <= x + height + 1; ix++)
			if(iy == y || iy == y + height + 1 || ix == x || ix == x + width + 1)
				mvaddch(iy, ix, 'X');
}
/* Shows only a map at position (shft_x/y)*/
void show_edited_map(struct level *play_ground, const int shft_y, const int shft_x)
{	/* shft_y, shft_x - shifts the map on the screen DRAFT */
	int y, x;
	map_type map;

	map = play_ground -> map;
	for(y = 0; y < MAP_SIZE; y++)
		for(x = 0; x < MAP_SIZE; x++){
			mvaddch(y + shft_y, x + shft_x, map[y][x]);
		}
	if(play_ground -> y != 0 && play_ground -> x != 0)
		mvaddch(play_ground-> y + shft_y, play_ground-> x + shft_x, '@');
}

void show_side_bar(const int shft_y, const int shft_x)
{
	int i,c;
	struct list *side_bar_content;
	struct list *temp;

	fill_the_list(&side_bar_content, "w - put a WALL", "u - put a USER", "space - put an empty SPACE", "r - ROCK", "R - put a locked rock", "o - put a POCKET", "s - save the map", "g - load a map", NULL);
	i = count_items(side_bar_content);

	for(c = 0; c < i; c++){
		mvprintw(shft_y + c, shft_x ,"%s", side_bar_content -> content);
		temp = side_bar_content;
		side_bar_content = side_bar_content -> next;
		free(temp);		
	}
}

/* Block moving out of a map coordinate [0...(MAP_SIZE - 1)]*/
void chk_pos(int *position)
{
	if(*position < 0){
		*position = 0;
		return;
	} else
	if(*position >= MAP_SIZE){
		*position = MAP_SIZE - 1;
		return;
	}
}

/* Depending on the screen size at x dimention map may take be in different 
places */
int get_map_position(const int mx)
{
	int middle_x;
	middle_x = mx / 2;
	/* If map size is larger than a screen	size.
			 20 - to show large text erlier */
	if(MIN_MAP_SHIFT * 3 + MAP_SIZE + SITE_BAR_WIDTH > mx)
		return 0;
	/*If width is larger than map + side bar*/ 
	else
		return middle_x - MIN_MAP_SHIFT - MAP_SIZE;
}
