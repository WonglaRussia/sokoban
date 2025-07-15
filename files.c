/* files.c */
#include "playground.h"
#include "files.h"
#include "map_functions.h"
#include <stdio.h> /* perror(),  */
#include <unistd.h> /* read() write() open() close() */
#include <fcntl.h> /* Symbolyc_constants like "O_RDONLY" etc */

/* To list campaigns */
int list_files();

/* Save the map in the campaign file.*/
/* 	num_lev - number of level. Counting from 0
	num_lev = 0 to create a new file */
int save_level(const char *camp_file_name, const int num_lev, struct level *level_addr)
{
	int fd,i;
	int offcet;
	offcet = sizeof(struct level);
	fd = open(camp_file_name, (O_WRONLY|O_CREAT), 0666);
	if(fd == -1){
		perror(camp_file_name);
		return 1;
	}
	i = lseek(fd, offcet * num_lev, SEEK_SET); /* Offcet. Skip prew levels */
	if (i == -1){
		perror(camp_file_name);
		return 2;
	}
	i = write(fd, level_addr, offcet);
	if (i == -1){
		perror("Can not save the map of the level.");
		return 3;
	}
	i = close(fd);
	if (i == -1){
		perror(camp_file_name);
		return 4;
	}
	return 0;
}
/* Get the level from the campaign file. == 0 - OK */
/* A level counting from 0 */
int load_level(const char *camp_file_name, const int num_lev, struct level *level_addr)
{
	int fd, i;
	int offcet;								/* (offcet of a single lev struct)*/
	offcet = sizeof(struct level);
	fd = open(camp_file_name, O_RDONLY);
	if(fd == -1){
		perror(camp_file_name);
		return 1;
	}
	i = lseek(fd, offcet * num_lev, SEEK_SET); /* Offcet. Skip prew num_levs */
	if (i == -1){
		perror(camp_file_name);
		return 2;
	}
	i = read(fd, level_addr, offcet);				/* Read the map of the num_lev */
	if (i == -1){
		perror("Can not get the map of the num_lev.");
		return 3;
	}
	i = close(fd);
	if (i == -1){
		perror(camp_file_name);
		return 4;
	}
	return 0;
}
