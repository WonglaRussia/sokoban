/* editor_files.c */ 
#include "playground.h"		/* struct level */
#include "files.h"				/* load_level() save_level() */ 
#include "files_support.h" /* choose_camp() choose_level() */
#include "editor_files.h"	
#include <stdlib.h>

/* save_e_camp load_e_camp functions are designed to let user
	0. Check level playground readiness. DRAFT
	1. Choose a campaign name (.camp file).
	2. Choose a level number (or just deside to append a level).
	3. Save/Load level */
void save_e_camp(struct level *level_addr)
{
	char *campaign_name;
	int level;

	campaign_name = malloc(255);		
	choose_camp(campaign_name, 255, 1);
	level =	choose_level(); /* DRAFT handle NULL level as quit */
	save_level(campaign_name, level, level_addr);	
	/* 	DRAFT Write host that playground was saved 
			DRAFT Check the map you want to save */
	free(campaign_name);
	return;
}



void load_e_camp(struct level *level_addr)
{
	char *campaign_name;
	int level;

	campaign_name = malloc(255);		
	choose_camp(campaign_name, 255, 0);
	level =	choose_level();
	load_level(campaign_name, level, level_addr);
	free(campaign_name);
	return;
}
