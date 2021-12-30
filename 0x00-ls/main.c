#include "headers_ls.h"

/**
 * main - Function that list the content of a directory
 * Description: this function try to replicate as cose as posible
 * the real behavior of the ls function present in linux
 * @argc: number of arguments passaed in the call
 * @argv: array of arguments (doble pointer).
 * Return: if successfull 0, otherwise -1
 */
int main(int argc, char *argv[])
{
    char *flags = NULL;
    char **valid_args = NULL;

    flags = validate_flags(argv); //_strdup memory
    printf("flags %s\n\n", flags);
    valid_args = validate_arguments(argc, argv); // malloc-calloc, errors

    printing(flags, valid_args);
    /* dirs = get_dirs(valid_args); */
    return 0;
}