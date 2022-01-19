#include "headers_ls.h"

/**
 * printing - Function that print
 * @flags: pointer where are allocated allowed flags.
 * @argv: pointer where are data to print allocated.
 */
void printing(char *flags, char **argv)
{
	int i;
	/*(void)flags;*/
	if (!argv)
		return;


	if (include(flags, '1') && !include(flags, 'l'))
	{
		for (i = 0; argv[i]; i++)
		{
			printf("%s", argv[i]);
			argv[i + 1] ? printf("\n") : 1;
		}
	}
	else if (include(flags, 'l'))
	{
		flag_l(argv);
	}
	else
		for (i = 0; argv[i]; i++)
			printf("%s  ", argv[i]);
	printf("\n");
}
