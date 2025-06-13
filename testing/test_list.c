/* test_list.c */
#include "list.h"
#include <stdio.h>
#include <string.h>
int main()
{
	struct list *main_m;
	char *str;
	fill_the_list(&main_m, "Quick play", "Test", "Test", "Test", "Test", "Exit", NULL);
	printf("Before get the content\n");
	printf("%d ***\n",count_items(main_m));
	str = main_m->content;
	printf("%s\n", main_m->content);
	return 0;
}
