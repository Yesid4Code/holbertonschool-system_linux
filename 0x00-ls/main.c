#include "headers_ls.h"

/**
 * main - Function that list the content of a directory
 * Description: this function try to replicate as cose as posible
 * the real behavior of the ls function present in linux
 * @argc: number of arguments passaed in the call
 * @argv: array of arguments (doble pointer).
 *
 * Return: if successfull 0, otherwise -1
 */
int main(int argc, char *argv[])
{
	char *flags = NULL, **valid_argv = NULL;
	char **files = NULL, **dirs = NULL;

	flags = validate_flags(argv);
	valid_argv = validate_arguments(argc, argv);
	sorting(flags, valid_argv);

	files = get_files(valid_argv);
	printing(flags, files);

	dirs = get_dirs(valid_argv);
	dir_process(argc, dirs, flags, files);

	free(flags);
	free_array(valid_argv);
	free_array(files);
	free_array(dirs);


	return (0);
}
