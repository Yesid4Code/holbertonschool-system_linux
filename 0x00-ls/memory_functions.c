#include "headers_ls.h"

/**
 * _calloc - function that reserved memory and fill it with zeros.
 * @sizepptr: number of strings inside the array line.
 * @sizetype: type of data
 *
 * Return: array filled with zeros.
 */
void *_calloc(unsigned int sizepptr, unsigned int sizetype)
{
	char *argline = NULL;

	if (sizepptr == 0 || sizetype == 0)
		return (NULL);
	argline = malloc(sizepptr * sizetype);
	if (!argline)
		return (NULL);
	argline = _memset(argline, 0, (sizepptr * sizetype));
	return (argline);
}

/**
 * _strdup - Function that return a pointer to duplicate string.
 * @str: pointer to a string.
 *
 * Return: Pointer to an string.
 */
char *_strdup(char *str)
{
	int i = 0, j;
	char *la;

	if (str == NULL)
		return (NULL);

	i = _strlen(str) + 1;
	la = malloc(i * sizeof(*str) + 1); /*reserve the space of memory*/
	if (!la)
	return (NULL);

	for (j = 0; j < i; j++)
		la[j] = str[j];
	la[j] = '\0';
	return (la);
}

/**
 * _memset - function that inicializate each character of the string with zero
 * @str: str
 * @a: Char to fill the string, a = "0"
 * @size: lenght of the string
 * Return: A pointer to string
 */
char *_memset(char *str, char a, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
		str[i] = a;
	return (str);
}
/**
 * free_array - function that deallocated reserved memory
 * @argv: double pointer to the allocated memory.
 */
void free_array(char **argv)
{
	if (argv)
	{
		for (int i = 0; argv[i]; i++)
		free(argv[i]);
		free(argv);
	}
}
