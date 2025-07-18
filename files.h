/* files.h */
#ifndef FILES_H
#define FILES_H

/* 	Save the level in the campaign file.
 	num_lev - number of level. Counting from 0
	num_lev = 0 to create a new file */
int save_level(const char *camp_file_name, const int num_lev, struct level *level_addr);

/* 	Load the level from the campaign file. == 0 - OK 
	A level counting from 0 
	leveil_addr is an address where level is saved */
int load_level(const char *camp_file_name, const int num_lev, struct level *level_addr);
#endif
