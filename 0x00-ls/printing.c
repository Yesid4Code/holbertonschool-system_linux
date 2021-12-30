#include "headers_ls.h"

void printing(char *flags, char **valid_args)
{
    //char **dirs = NULL;
    char **dir_content = NULL;
    DIR *dir = NULL;
    struct dirent *read = NULL;
    struct stat file;
    int j = 0;

    //files = get_files(valid_args);
    sorting(flags, valid_args); //S, 8, t, r
    printf("files:\n");
    for(int i=0; valid_args[i]; i++)
    {
        if(lstat(valid_args[i], &file) == 0 && S_ISREG(file.st_mode))
        {
            printf("%s  ", valid_args[i]);
            /*print_data(valid_args[i], flags);

        }*/
        }
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
                //printf("%s  ", read->d_name);
                dir_content[j] = _strdup(read->d_name); //Memory use
                read = readdir(dir);
                j++;
            }
            closedir(dir);
            printf("\n");
        }
    }
    sorting(flags, dir_content);
    for(int i=0; dir_content[i]; i++)
    {
        printf("%s  ", dir_content[i]);
    }
        //sorting(flags, dir_content);
        //flar a, A. ocultos o no?
        //normal: no incluye a,A: elimino, muevo alfinal y elimino
}
/*
void *print_data(char *arg, char *flags)
{

    * /almacenar en un **, enviar a función que solo imprima
    // si está -1 pero no -l, salto de linea
    // si está -l, imprimir todo.
    struct stat file;

    printf();
}
*
void print_dir(char **dirs) // flag
{
    //int *copy = v;
    DIR *dir = NULL;
    struct dirent *entity;
    *
    while(v != NULL) //entity = readdir(dir);
    {
        print("%s  ", )
    }*/
    /* entity->d_type != DT_UNKNOWN && entity->d_name[0] != *"."*/
    /*<<<<<<<<<<<<<<for (int i=0; dirs[i]; i++)
    {
        dir = opendir(dirs[i]);
        if(dir == NULL)
        {
            printf("ERROR\n");
            printf("ls: cannot access 'aquivaelerror': No such file or directory");
            //return -1;
        }
        entity = readdir(dir);
        while ( entity != NULL )
        {
            printf("%s  ", entity->d_name);
            entity = readdir(dir);
            //if directory arr=entity
        }
        //print_dir(recursion) with flag -R
        closedir(dir);
        //return 0;
    }
}
/

    //print_dir(argv[1]);
    for(int i = 1; i < argc; i++)
    {
        printf("%s:\n", argv[i]);
        print_dir(argv[i]);
        if(i < argc -1)
            printf("\n\n");
    }*/