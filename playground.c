/* playground.c */

#include "map_function.h"
#include "map_state.h"
#include "playground.h"

void play_map(const map_type map)
{
	int key;
	void *playground;
	int y_usr_location, x_usr_location;
/* Make local copy of the source map 
to be able change map state, save the progress et.c. */
	playground = malloc(MAP_SIZE * MAP_SIZE * sizeof(int)); 
	copy_map(map,playground);
/* Remove user from the playground and get it`s coordinates. */
	extract_usr(playground, &y_usr_location, &x_usr_location);
	while(1){
		key = getch(); /* DRAFT timeout set here */
		switch(key){
			case ERR: 	break;
			case 'q':	return;
			default:	{
				change_map_state(key, playground, &y_usr_location, &x_usr_location);
				if(check_map(playground) == 0)
					{
						clear();
						printw("YOU WIN!!!");
						refresh();
					}
				else
					show_map(key, playground, &y_usr_location, &x_usr_location);
			}
		}
	}
	free(playground);
}