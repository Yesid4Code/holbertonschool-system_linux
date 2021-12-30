#include "headers_ls.h"

/**
 * validate_flags - functions that validates the sent flags
 * @argv: doble pointer of arguments sent by the user.
 * @flags: pointer to a string of flags.
 * Return: pointer to valid flags.
 */
char *validate_flags(char **argv)
{
    char *valid_flags = "1aAlrStR";
    char buff[32] = {'\0'}, identified_flag[2];
    char *flags = NULL;

    for(int i = 1; argv[i] != NULL; i++)
    {
        if(argv[i][0] == '-')
        {
            for(int j = 0; argv[i][j]; j++)
            {
                if(include(valid_flags, argv[i][j]) && !include(buff, argv[i][j]))
                {
                    identified_flag[0] = argv[i][j], identified_flag[1] = '\0';
                    _strcat(buff, identified_flag);
                }
            }
        }
    }

    if (_strlen(buff) != 0)
        flags = _strdup(buff);
    else //se podría eliminar, función por defecto, flag -A,
    {   /* 8: alphabetic order: personal flag */
        identified_flag[0] = '8', identified_flag[1] = '\0';
        _strcat(buff, identified_flag);
        flags = _strdup(buff);
    }
    return flags;
}

/**
 * validate_arguments -function that validate all arguments
 * @argc: number of arguments sent by user.
 * @argv: double pointer to the arguments passed in the call
 *
 * Return: double pointer to valid arguments.
 */
char **validate_arguments(int argc, char *argv[]) // char **errors
{
    char **valid_args = NULL;
    int m = 0;
    struct stat file;

    valid_args = _calloc(argc, sizeof(*valid_args));
    for(int i=1; argv[i] != NULL; i++)
    {
        if (lstat(argv[i], &file) == 0 && S_ISREG(file.st_mode))
        {
            valid_args[m] = _strdup(argv[i]), m++;
        }
        else if (lstat(argv[i], &file) == 0 && S_ISDIR(file.st_mode))
            {
                valid_args[m] = _strdup(argv[i]), m++;
            }
        else if(_strcmp(argv[i],"---") == 0)//error:----
        {
            fprintf(stderr,
            "%s: cannot access '%s': No such file or directory\nTry 'hls --help' for more information.\n",
            argv[0], argv[i]);
            //free(errors); exit2;
        }
        else if(argv[i][0] == '-' && _strlen(argv[i]) > 1)
            continue;
        else
        {
            fprintf(stderr,
            "%s: cannot access %s: No such file or directory\n",
            argv[0], argv[i]);
        }

    }
    if (m == 0)
    {
        free(valid_args), valid_args = malloc(sizeof(*valid_args));
        if(valid_args == NULL)
            return NULL;
        valid_args[0] = _strdup(".");
    }
    return valid_args;
}