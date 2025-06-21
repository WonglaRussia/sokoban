/* files.c */
#include "files.h"
#include <stdio.h> /* perror */

/* To list campaigns */
int list_files();
/* Save the map in the campaign file.*/
/* level = 0 to create a new file */
int save_map(const char *campaign, const int level, void *src)
{
	int fd,i;
	int offcet;
	offcet = MAP_SIZE * MAP_SIZE * sizeof(int);
	fd = open(campaign, O_WRONLY|O_CREAT);
	if(fd == -1){
		perror(campaign);
		return 1;
	}
	i = lseek(fd, offcet * level, SEEK_SET); /* Offcet. Skip prew levels */
	if (i == -1){
		perror(campaign)
		return 2;
	}
	i = write(fd, src, offcet);
	if (i == -1){
		perror("Can not save the map of the level.");
		return 3;
	}
	i = close(fd);
	if (i == -1){
		perror(campaign);
		return 4;
	}
	return 0;
}
/* Get the map from the campaign file. == 0 - OK */
/* Level conunting from 0 */
int load_map(const char *campaign, const int level, void *dst)
{
	int fd, i;
	int offcet;								/* (offcet of a single level)*/
	offcet = MAP_SIZE * MAP_SIZE * sizeof(int);
	fd = open(campaign, O_RDONLY);
	if(open == -1){
		perror(campaign);
		return 1;
	}
	i = lseek(fd, offcet * level, SEEK_SET); /* Offcet. Skip prew levels */
	if (i == -1){
		perror(campaign)
		return 2;
	}
	i = read(fd, *dst, offcet);				/* Read the map of the level */
	if (i == -1){
		perror("Can not get the map of the level.");
		return 3;
	}
	i = close(fd);
	if (i == -1){
		perror(campaign);
		return 4;
	}
	return 0;
}