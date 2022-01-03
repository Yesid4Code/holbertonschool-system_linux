#include "headers_ls.h"

/**
 * sorting - function that sort an 2D array.
 * @flags: pointer to array of valid flags.
 * @argv: double pointer to 2D array to be sorted.
 *
 * Return: doble pointer of the sorted array.
 */
char **sorting(char *flags, char **argv)
{
	if (!include(flags, 't') && !include(flags, 'S'))
		sort_default(argv);
	else
	{
		for (int i = 0; flags[i]; i++)
		{
			if (flags[i] == 't')
				sort_time(argv);
			else if (flags[i] == 'S')
				sort_size(argv);
		}
	}
	if (include(flags, 'r'))
		sort_reverse(argv);

	return (argv);
}

/**
 * sort_default - function that sorts if no flags were found
 * @argv: pointer where data are allocated.
 *
 * Return: pointer to sorted and allocated data.
 */
char **sort_default(char **argv)
{
	return (argv);
}

/**
 * sort_time - function that sort data by time
 * @argv: pointer where data are allocated.
 *
 * Return: pointer to sorted and allocated data.
 */
char **sort_time(char **argv)
{
	return (argv);
}

/**
 * sort_size - function that order by the size of a file.
 * @argv: pointer where data are allocated..
 *
 * Return: pointer to sorted and allocated data.
 */
char **sort_size(char **argv)
{
	return (argv);
}

/**
 * sort_reverse - function that reverse
 * @argv: pointer where data are allocated.
 *
 * Return: pointer to sorted and allocated data.
 */
char **sort_reverse(char **argv)
{
	return (argv);
}
