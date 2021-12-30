#include "headers_ls.h"

void printing(char *flags, char **valid_args)
{
    char **dir_content = NULL;
    DIR *dir = NULL;
    struct dirent *read = NULL;
    struct stat file;
    int j = 0;

    sorting(flags, valid_args);
    printf("files:\n");
    for(int i=0; valid_args[i]; i++)
    {
        if(lstat(valid_args[i], &file) == 0 && S_ISREG(file.st_mode))
            printf("%s  ", valid_args[i]);
    }
    printf("\ndir_content\n");
    for(int i=0; valid_args[i]; i++)
    {
        if(lstat(valid_args[i], &file) == 0 && S_ISDIR(file.st_mode))
        {
            dir_content = _calloc(100, sizeof(*dir_content));
            dir = opendir(valid_args[i]);
            if(dir == NULL)
            {
                printf("ERROR");
                //return ;
            }
            read = readdir(dir);
            j = 0;
            while(read != NULL)
            {
                dir_content[j] = _strdup(read->d_name);
                read = readdir(dir);
                j++;
            }
            closedir(dir);
            printf("\n");
        }
    }
    sorting(flags, dir_content);
    //flar a, A. ocultos o no?
    //normal: no incluye a,A: elimino, muevo alfinal y elimino
    for(int i=0; dir_content[i]; i++)
    {
        printf("%s  ", dir_content[i]);
    }
}