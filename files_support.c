/* files_support.c */
#include "list.h"		/* append_item(),get_list_content(),list*,count_items()*/
#include "menu.h"		/* play_menu() */
#include "files_support.h"
#include <stdlib.h> /* malloc(), free() */
#include <dirent.h>
#include <string.h>	/* strncpy() strstr() */
#include <curses.h>
/* form a string in situation when timeout is set */
static void get_str(char *str, int limit, int y, int x)
{
	int key;

	key = 0;
	if(limit == 1){
		str[0] = 0;	
		return;
	}
	while(1){
		key = getch(); /* char is in key */
		if(key != ERR)
			break;
	}

	if(key == 10){ 	/* new line */
		*str = 0;
		return;
	} else {				/* DRAFT check the file system requirements to a file name */
		str[0] = key; /* append the letter */
		move(y, x);		/* show the letter */
		addch(key);
		refresh();
		get_str(&str[1], limit-1, y, x+1);
	}
}
/* converts string to integer
	if string conteins letters return -1 */
static int convert_chars(char *str)
{
	int d, tail;

	if(!str[0])					/* string ended */
		return 0;
	d = str[0] - 48; 	/* convert current ascii to int '0' = 30*/
	if( d < 0 || d > 9 || (-1 ==	(tail = convert_chars(str + 1))))
		return -1; 			/* out of digit range here or in the tail */
	d *= (strlen(str) * 10);	
	return d + tail;
}
/* Creates menu of .camp files suited in . directory.
	Retuns the name of the chosen file.
	Returns NULL if user chose 'quit' */
void	choose_camp(char *cmp_name, const int len_mx)
{
	size_t name_len;
	int desition;
	char *tmp;
	struct list *options; /* list of .camp files */
	DIR *directory;
	struct dirent *dp;
	int my, mx;	/*DRAFT let getting string be separate function !!*/
	/* DRAFT add .camp suffix mandatorily */	
	tmp = malloc(len_mx);
	options = NULL;		
	directory = opendir(".");

	while((dp = readdir(directory)) != NULL){
		if(strstr(dp -> d_name, ".camp") == NULL)	
			continue;			/* skip files witout .camp suffix */
		else{						/* add .camp file name as an option */
			append_item(dp -> d_name, &options);
		}
	}
	append_item("CREATE A NEW CAMPAIGN", &options);

	/* Choose the option 1 = 1st option */
	desition = play_menu(options);

		/*DRAFT let getting string be separate function !!*/
	if(desition == count_items(options)){/* New campaign */
	/* Type a new file name */
		clear();
		getmaxyx(stdscr, my, mx);
		mvprintw(my/2 - 1, mx/2 - 10, "Type the campaign name.");
		get_str(tmp, len_mx, my/2, mx/2 - 10);
	}	else {
	/* Copy the chosen file name */
	  tmp =	get_list_content(desition, options);
		name_len = strlen(tmp);
		if(name_len > len_mx){
			free(tmp);
			return;
		}
	}
  strncpy(cmp_name, tmp, len_mx - 1);
	free(tmp);
	return;
}

int choose_level(void)
{ /*DRAFT add check of the existing levels */
	int my, mx;
	int level = 1;
	char *str_lv;
	char *msg = "Type the number of the campaign's level you whant. (3 digits)";
	char *msg_err = "Only digits. Three digits are valid. Try again";	
	str_lv = malloc(4);
	while(1){					/* In cycle we tries our attempts */
		getmaxyx(stdscr, my, mx);
		clear();
		if(level == -1) /* -1 |=> this is not the first try */ 
			mvprintw(my/2 - 1, (mx - strlen(msg_err))/2,"%s", msg_err);
		else
			mvprintw(my/2 - 1, (mx - strlen(msg))/2,"%s", msg);
		get_str(str_lv, 4, my/2, mx/2);
		level = convert_chars(str_lv);
		if(level == -1)	/* symbols in the text */
			continue;			/* try again */
		else
			break;				/* Function returned appropriate value */
	}
	free(str_lv);		
	return level;	/* DRAFT check the value only 0-9 levels !!! */
}
