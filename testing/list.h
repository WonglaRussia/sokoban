/* list.h */
#ifndef LIST_H
#define LIST_H
#define MAX_SIZE_C 260
struct list{
	char *content;
	struct list *next;
};

/* Returns the quantity of items in the list 
in range from 1 to integer. 0 = NULL */
int count_items(const struct list *options);

/* Returns the content of the item in the list
		according to item`s serial number */
char * get_list_content(const int seq_num, struct list *first);

/* Appends the item to the END of the list
		To create a new list set *first == NULL */
void append_item(const char *value, struct list **first);

/* Fill the list.	With char *.
First variable is a pointer at the first struct address. 
Then variables "const char *" that will be used as content of items in the list
the last variable must be "NULL" 
fill_the_list(options, "First option", "Second option", NULL); */
void fill_the_list(struct list **first, ...);
#endif
