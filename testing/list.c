/* list.c */
#include "list.h"
#include <string.h> 	/* strlen() */
#include <stdlib.h>		/* malloc() memcpy() */
#include <stdio.h>		/* sprintf() */
#include <stdarg.h>		/* variadic function */

/* Returns the quantity of items in the list 
in range from 1 to integer. 0 = NULL */
int count_items(const struct list *options)
{
	if(options == NULL)
		return 0;
	else
		return 1 + count_items(options -> next);
}
/* Returns the content field of the item in the list
		according to item`s serial number (1st item == 1 seq_num)*/
char * get_list_content(const int seq_num, struct list *first)
{
	int i;
	struct list *tmp;
	tmp = first;
	for(i = 1; i < seq_num; i++)
		tmp = tmp -> next;
	if(tmp == NULL)
		return NULL;
	return tmp -> content;
}
/* As soon as a list appends at the end 
There is a necessity to know the last item*/
static struct list *get_last(struct list *first)
{
	if(first->next == NULL)
		return first;
	else
		return get_last(first->next);
}
/* Appends the item to the END of the list
To create new list can use NULL as the second argumen*/
void append_item(const char *value, struct list **first)
{
	struct list *last, *tmp;
	last = malloc(sizeof(struct list));	/* Create the last item */
	last->content = malloc(260);
	strncpy(last->content, value, (size_t)260);
	last->next = NULL;
	if((*first) != NULL) {				/* Appends the item ... */		
		tmp = get_last(*first);			/*...to the existing list */
		tmp->next = last;
	}
	else								/* struct list *first == NULL */
		*first = last;					/* There is no a list as an argument */
}
/* Fill the list.
First variable is a pointer at the first struct address 
pass variables using type "const char *s"
the last variable must be "NULL" */
void fill_the_list(struct list **first, ...)
{
	char *string;
	va_list vl;	
	va_start(vl,first);
	*first = NULL;
	for(string = va_arg(vl, char*); string != NULL ; string = va_arg(vl, char*))
		append_item(string, first);
	va_end(vl);
	return;
}
