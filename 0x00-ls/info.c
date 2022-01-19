#include "headers_ls.h"

/**
 * flag_l - function that print info of a document.
 * @argv: files to print with extra info.
 */

void flag_l(char **argv)
{
	int i;
	char *perms, *date;
	struct stat file;
	struct passwd *usr;
	struct group *grp;

	for (i = 0; argv[i]; i++)
	{
		if (lstat(argv[i], &file) == 0 &&
			(S_ISREG(file.st_mode) || S_ISDIR(file.st_mode)))
		{
			perror("lstat");
			/*
			*free(flags);
			free_array(valid_argv);
			free_array(files);
			free_array(dirs); PROBLEMSSS flag: -l
			*/
			exit(2); /*EXIT_FAILURE*/
		}
		perms = permissions(file);
		usr = getpwuid(file.st_uid);
		grp = getgrgid(file.st_gid);
		date = get_date(file); /*time ^;*/
		printf("%s %ld %s %s %ld %s %s\n",
			perms,
			(long) file.st_nlink,
			usr->pw_name != NULL ? usr->pw_name : "",
			grp->gr_name != NULL ? grp->gr_name : "",
			(long) file.st_size,
			date,
			argv[i]);
		free(perms), free(date);
	}
}

/**
 * permissions - function that get permissions of a file.
 * @file: file to found permissions.
 *
 * Return: pointer where permissions were allocated.
 */
char *permissions(struct stat file)
{
	char *permissions = NULL;
	mode_t perm = file.st_mode;

	permissions = malloc(11 * sizeof(char));
	if (permissions == NULL)
		return (NULL);

	permissions[0] = ((perm & S_IFMT) == S_IFDIR) ? 'd' : '-';
	permissions[1] = (perm & S_IRUSR) ? 'r' : '-';
	permissions[2] = (perm & S_IWUSR) ? 'w' : '-';
	permissions[3] = (perm & S_IXUSR) ? 'x' : '-';
	permissions[4] = (perm & S_IRGRP) ? 'r' : '-';
	permissions[5] = (perm & S_IWGRP) ? 'w' : '-';
	permissions[6] = (perm & S_IXGRP) ? 'x' : '-';
	permissions[7] = (perm & S_IROTH) ? 'r' : '-';
	permissions[8] = (perm & S_IWOTH) ? 'w' : '-';
	permissions[9] = (perm & S_IXOTH) ? 'x' : '-';
	permissions[10] = '\0';
	return (permissions);
}

/*
*-rw-rw-r-- 1 yesid4code yesid4code    2492 ene  2 23:31 arguments.c
-rw-rw-r--
1
yesid4code
yesid4code
2492
ene  2 23:31
arguments.c
*/
/**
 * get_date - function to get the date of a file.
 * @file: file to analize.
 *
 * Return: pointer with permissions.
 */
char *get_date(struct stat file)
{
	char *date = _strdup(ctime(&file.st_mtime));

	return (date);
}
