#include "headers_ls.h"

/**
 * get_files - function that get files from argv.
 * Description:
 * @argv: pointer where the files are allocated.
 * Return: pointer where the files were allocated
 */
char **get_files(char **argv)
{
    int j = 0;
    char **files = NULL;
    struct stat file;

    files = _calloc(100, sizeof(*files));
    for(int i=0; argv[i]; i++)
    {
        if(lstat(argv[i], &file) == 0 && S_ISREG(file.st_mode))
            files[j] = _strdup(argv[i]), j++;
    }
    if(j==0)
    {
        free(files);
        return NULL;
    }
    return files;
}

/**
 * get_dirs - function that get directories from argv.
 * @argv: pointer where directories are allocated.
 * Return: pointer where directories were allocated.
 */
char **get_dirs(char **argv)
{
    int j=0;
    char **directories = NULL;
    struct stat dir;

    directories = _calloc(100, sizeof(*directories));

    for(int i=0; argv[i]; i++)
    {
        if(lstat(argv[i], &dir) == 0 && S_ISDIR(dir.st_mode))
            directories[j] = _strdup(argv[i]), j++;
    }
    if(j==0)
    {
        free(directories);
        return NULL;
    }
    return directories;
}

/**
 * dir_process - function that process directories
 * @flags: string of flags allowed.
 * @argv: pointer where directories are allocated
 * Return: 0: sucessfull, -1 in case of errors.
 */
int dir_process(char *flags, char **argv, char **files)
{
    int j = 0;
    char **dir_content = NULL;
    struct dirent *read = NULL;
    struct stat file;
    DIR *dir = NULL;

    if(!argv)
        return -1;

    for(int i=0; argv[i]; i++)
    {
        if(lstat(argv[i], &file) == 0 && S_ISDIR(file.st_mode))
        {
            dir_content = _calloc(100, sizeof(*dir_content));
            dir = opendir(argv[i]);
            if(dir == NULL)
            {
                printf("ERROR");
                return -1;
            }
            j = 0;
            while((read = readdir(dir)))
                dir_content[j] = _strdup(read->d_name), j++;

            closedir(dir);
        }
        if(files)
            printf("\n%s:\n", argv[i]);
        printing(flags, dir_content);
        free_array(dir_content);
    }
    return 0;
}
