/* files_support.h */
#ifndef FILES_SUPPORT_H 
#define FILES_SUPPORT_H

/* 
	Creates menu of .camp files suited in . directory.
	Retuns the name of the chosen file.
	Returns NULL if user chose 'quit' 
	Set new_name != 0 if you whant add optiotion typing new string. (New file).
*/
void choose_camp(char *cmp_name, const int len_mx, int new_name);

/*
	Propose to type (choose) a number. Returns the number as an integer.
*/

int choose_level(void);
#endif
