#include "headers_ls.h"

/**
 * sorting - function that sort an 2D array.
 * @flags: pointer to array of valid flags.
 * @argv: double pointer to 2D array to be sorted.
 * Return: doble pointer of the sorted array.
 */
char **sorting(char *flags, char **argv)
{
    if(!include(flags, 't') && !include(flags, 'S'))
        sort_default(argv);
    else
    {
        for(int i=0; flags[i]; i++)
        {
            if(flags[i] == 't')
                sort_time(argv);
            else if(flags[i] == 'S')
                sort_size(argv);
        }
    }
    if(include(flags, 'r'))
        sort_reverse(argv);

    return argv;
}

char **sort_default(char **argv)
{
    return argv;
}

char **sort_time(char **argv)
{
    return argv;
}

char **sort_size(char **argv)
{
    return argv;
}

char **sort_reverse(char **argv)
{
    return argv;
}
