/*  */
#include "list.h"
struct list{
	char content[260];
	struct list *next;
};
/* Returns value in range [-1,0-int]; 
	-1 - error
	int quantity of created items
*/
int create_list()
