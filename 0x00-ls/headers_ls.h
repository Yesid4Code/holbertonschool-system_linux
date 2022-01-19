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
#include <pwd.h>
#include <grp.h>
#include <time.h>

/* arguments functions */
char *validate_flags(char **argv);
void argument_errors(char **argv);
char **validate_arguments(int argc, char *argv[]);

/* files functions */
char **get_files(char **argv);
char **get_dirs(char **argv);
int dir_process(int argc, char **argv, char *flags, char **files, char *hls);

/* printing functions */
void printing(char *flags, char **valid_args);

/* sorting functions */
char **sorting(char *flags, char **argv);
char **sort_default(char **argv);
char **sort_time(char **argv);
char **sort_size(char **argv);
char **sort_reverse(char **argv);

/* info functions */
void flag_l(char **argv);
char *permissions(struct stat file);
char *get_date(struct stat file);

/* Memory functions */
void *_calloc(unsigned int nm, unsigned int sz);
char *_strdup(char *str);
char *_memset(char *str, char a, unsigned int size);
void free_array(char **argv);

/* Auxiliar functions */
bool include(char *string, char arg);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif /* END HEADERS_LS */
