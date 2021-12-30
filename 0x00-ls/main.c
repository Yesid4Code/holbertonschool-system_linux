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



    return 0;
}


/*/valid_args = get_dir(argv);
printf("\n");
for (int i=0; valid_args[i] != NULL; i++)
{
    if (lstat(valid_args[i], &file) == 0 && S_ISREG(file.st_mode))
        printf("argument file: %s: \n", valid_args[i]);
    else
        printf("argument dir: %s: \n", valid_args[i]);
}
printf("\nBegin\n")*


    si es un archivo imprime el archivo
    printdata

    segundo ciclo, si es un dir
    dir_process
    -> dir: crear array con la info, la trae.
    continuar: usar sorting, printdata, free dir, 
    endfor

    // printing_info_files(flags, valid_args) if -1-l-1
    //1aAl; //rStR

    //dirs = get_dirs(valid_args);
    / if (!include(flags, "R"))*/