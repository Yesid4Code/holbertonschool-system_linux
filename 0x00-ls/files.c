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
int dir_process(int argc, char **argv, char *flags, char **files)
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
            {
                if(include(flags, 'a'))
                    dir_content[j] = _strdup(read->d_name), j++;
                else if(include(flags, 'A'))
                {
                    if(_strcmp(read->d_name, ".") != 0 && _strcmp(read->d_name, "..") != 0)
                        dir_content[j] = _strdup(read->d_name), j++;
                }
                else
                {
                    if(_strcmp(read->d_name, ".") != 0 &&
                                    _strcmp(read->d_name, "..") != 0 &&
                                    read->d_name[0] != '.')
                        dir_content[j] = _strdup(read->d_name), j++;
                }
            }
            closedir(dir);
        }
        if(files)
            printf("\n");
        if(argc > 2)
            printf("%s:\n", argv[i]);
        printing(flags, dir_content);
        if(argv[i+1])
            printf("\n");
        free_array(dir_content);
    }
    return 0;
}
