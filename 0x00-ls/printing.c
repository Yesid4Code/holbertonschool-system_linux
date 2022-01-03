#include "headers_ls.h"

/**
 * printing - Function that print
 * @flags: pointer where are allocated allowed flags.
 * @argv: pointer where are data to print allocated.
 */
void printing(char *flags, char **argv)
{
	(void)flags;
	if (!argv)
		return;

	for (int i = 0; argv[i]; i++)
	{
		printf("%s  ", argv[i]);
	}
	printf("\n");
}
