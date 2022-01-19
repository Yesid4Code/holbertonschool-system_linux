#include "headers_ls.h"

/**
 * argument_errors - function that identify errors on arguments sent by user.
 * @argv: pointer to arguments sent.
 * Return: nothing.
 */
void argument_errors(char **argv)
{
	int i;
	struct stat file;

	for (i = 0; argv[i]; i++)
	{
		if (lstat(argv[i], &file) == 0 &&
				(S_ISREG(file.st_mode) || S_ISDIR(file.st_mode)))
			continue;
		else if (_strcmp(argv[i], "---") == 0) /*//error:----*/
		{
			fprintf(stderr,
			"%s: cannot access %s: No such file or directory\nTry 'hls --help' for more information.\n",
			argv[0], argv[i]);
			/*free(errors);*/
			exit(2);
		}
		else if (argv[i][0] == '-' && _strlen(argv[i]) > 1)
			continue;
		else
		{
			fprintf(stderr,
			"%s: cannot access %s: No such file or directory\n",
			argv[0], argv[i]);
			/*exit(2);*/
		}
	}
}

/**
 * validate_flags - functions that validates the sent flags
 * @argv: doble pointer of arguments sent by the user.
 *
 * Return: pointer to valid flags.
 */
char *validate_flags(char **argv)
{
	char *valid_flags = "1aAlrStR";
	char buff[32] = {'\0'}, identified_flag[2];
	char *flags = NULL;
	int i, j;

	for (i = 1; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '-')
		{
			for (j = 0; argv[i][j]; j++)
			{
				if (include(valid_flags, argv[i][j]) && !include(buff, argv[i][j]))
				{
				identified_flag[0] = argv[i][j], identified_flag[1] = '\0';
				_strcat(buff, identified_flag);
				}
			}
		}
	}


	if (_strlen(buff) != 0)
		flags = _strdup(buff);
	else	/*se podría eliminar, función por defecto, flag -A,*/
	{	/* 8: alphabetic order: personal flag */
		identified_flag[0] = '8', identified_flag[1] = '\0';
		_strcat(buff, identified_flag);
		flags = _strdup(buff);
	}
	return (flags);
}


/**
 * validate_arguments -function that validate all arguments
 * @argc: number of arguments sent by user.
 * @argv: double pointer to the arguments passed in the call
 *
 * Return: double pointer to valid arguments.
 */
char **validate_arguments(int argc, char *argv[]) /* char **errors */
{
	int i, m = 0;
	char **valid_argv = NULL;
	struct stat file;

	valid_argv = _calloc(argc, sizeof(*valid_argv));
	if (!valid_argv)
		return (NULL);

	for (i = 1; argv[i] != NULL; i++)
	{
		if (lstat(argv[i], &file) == 0 &&
		(S_ISREG(file.st_mode) || S_ISDIR(file.st_mode)))
		valid_argv[m] = _strdup(argv[i]), m++;
	}

	if (m == 0)
	{
		free(valid_argv), valid_argv = _calloc(2, sizeof(*valid_argv) + 1);
		if (valid_argv == NULL)
			return (NULL);
		valid_argv[0] = _strdup(".");
	}
	return (valid_argv);
}
