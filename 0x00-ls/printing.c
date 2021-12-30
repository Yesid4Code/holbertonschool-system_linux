#include "headers_ls.h"

void printing(char *flags, char **argv)
{
    (void)flags;
    if(!argv)
        return ;

    for(int i=0; argv[i]; i++)
    {
        printf("%s  ", argv[i]);
    }
    printf("\n");
}
