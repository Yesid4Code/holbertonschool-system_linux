#ifndef _GETLINE_H
#define _GETLINE_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ_SIZE 1024

/*
line buffer \n
file buffer
no buffer
*/



/**
 * 
 * 
 */
typedef struct fd
{
	int fd;
	int idx;
	ssize_t bytes;
	char *buffer;
	struct fd *next;
}fd_t;

char *_getline(const int fd);
fd_t *get_fd(fd_t **head, const int fd);
fd_t *add_fd(fd_t **head, const int fd);
char *get_line(fd_t *file);
void free_fd(fd_t **head);

#endif /*_GETLINE_H */
