#ifndef LIST_H
#define LIST_H
#define MAX_SIZE_C 260
struct list{
	char *content;
	struct list *next;
};

int count_items(const struct list *options);
void fill_the_list(struct list **first, ...);
#endif