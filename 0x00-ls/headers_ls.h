#ifndef HEADERS_LS_H_
#define HEADERS_LS_H_

/* system */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

/* Auxiliar functions */
void *_calloc(unsigned int nm, unsigned int sz);

//void print_dir(char *v);
char *validate_flags(char **argv);
char **validate_arguments(int argc, char *argv[]);
void printing(char *flags, char **valid_args);
char **sorting(char *flags, char **argv);
//
bool include(char *string, char arg);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_memset(char *str, char a, unsigned int size);

/* sorting functions */
char **sorting(char *flags, char **argv);
char **sort_default(char **argv);
char **sort_time(char **argv);
char **sort_size(char **argv);
char **sort_reverse(char **argv);

#endif /* END HEADERS_LS */

/*
struct file
{
    char name = NULL;
    char type_file = NULL;
    long int size = NULL
    unsigned long int time

    struct file *prev;
    struct file *next;
} file; if data != NULL print
*/
/*
print -->
_strcmp;
store (files) >
order alfabético minúsculas primero>
*/
/*
#ifndef HEADERSHELL_H_
#define HEADERSHELL_H_

#define _GNU_SOURCE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
*/