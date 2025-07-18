/* editor_files.h */
#ifndef EDITOR_FILES_H 
#define EDITOR_FILES_H 

/*	save_e_camp load_e_camp functions are designed to let user
	DRAFT 0. Check level playground readiness. 
	1. Choose a campaign name (.camp file).
	2. Choose a level number (or just deside to append a level).
	3. Save/Load level */
void save_e_camp(struct level *level_addr);
void load_e_camp(struct level *level_addr);
#endif
