#include "headers_ls.h"
// default -f NO, default alfabéticamente.

//char **sorting_dafult( )
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
        printf("LOCA\n");
        for(int i=0; flags[i]; i++)
        {
            printf("LOCA2\n");
            if(flags[i] == 't')
            {
                sort_time(argv);
                printf("LOCA3\n");
            }
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
    printf("\nprinting by default \n");
    return argv;
}

char **sort_time(char **argv)
{
    printf("\nprinting by time \n");
    return argv;
}

char **sort_size(char **argv)
{
    printf("\nprinting by size \n");
    return argv;
}

char **sort_reverse(char **argv)
{
    printf("\nprinting with reverse \n");
    return argv;
}