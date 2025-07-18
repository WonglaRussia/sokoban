/* camp.c */
#include "playground.h" /* play_level(), struct level*/
#include "files_support.h"
#include "files.h"
#include "camp.h"
#include <stdio.h>			/* fseek() */
#include <stdlib.h>			/* malloc(), free() */
#define LENGTH 255

void camp(void)
{
	int lvl;
	char *cmp_name;
	struct level *playground;

	cmp_name = malloc(LENGTH);	
	playground = malloc(sizeof(struct level));

	choose_camp(cmp_name,	LENGTH, 0);	/* file name is in cmp_name */
/* DRAFT add check of file format corruption */
	for( lvl=0; 0 == load_level(cmp_name, lvl, playground); lvl++ ){
		/* play level by level until load function did not retrun != 0 ) */	
			play_level(playground);	 
	}
	free(cmp_name);
	return;
}
