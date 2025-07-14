/* files.h */
#ifndef FILES_H
#define FILES_H
int save_level(const char *camp_file_name, const int num_lev, struct level *level_addr);
int load_level(const char *camp_file_name, const int num_lev, struct level *level_addr);
#endif
