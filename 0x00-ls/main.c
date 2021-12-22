#include <stdio.h>
#include <string.h>
#include <dirent.h>
/**
 * main - Function that list the content of a directory
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: if successfull 0, otherwise -1
 */
int main(int argc, char *argv[])
{
    DIR *dir = NULL;
    struct dirent *entity;

    if (argc == 1)
        dir = opendir(".");
    else
        dir = opendir(argv[1]);
    if (dir == NULL) {
        /*errno*/
        return -1;
    }

    entity = readdir(dir);
    /* entity->d_type != DT_UNKNOWN && entity->d_name[0] != *"."*/
    while ( entity != NULL )
    {
        printf("%s  ", entity->d_name);
        entity = readdir(dir);
    }

    closedir(dir);
    printf("\n");
    return 0;
}