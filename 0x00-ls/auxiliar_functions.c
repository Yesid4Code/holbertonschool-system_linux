#include "headers_ls.h"

/**
 * _calloc - Function that allocates memory for an array.
 * @nm: Number of elemens.
 * @sz: Size of each elemens.
 *
 * Return: a pointer.
 *
void *_calloc(unsigned int nm, unsigned int sz)
{
	unsigned int i;
	char *p;

	if (nm == 0 || sz == 0)
		return (NULL);          /printf(Memory not available.*
	p = malloc(sz * nm);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < nm * sz; i++) //ALEJO _memset(p, 0, (nm * sz))
		p[i] = 0;
	return (p);
}
*/

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
	argline = malloc(sizepptr * sizetype + 1);
	if (!argline)
		return (NULL);
	argline = _memset(argline, 0, (sizepptr * sizetype));
	return (argline);
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

bool include(char *string, char arg)
{
    for(int i = 0; i < _strlen(string); i++)
    {
        if(string[i] == arg)
            return true;
    }
    return false;
}

/**
 * _strlen -  returns the length of a string.
 * @s: char
 * Return: i
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 **_strcat - functions that concatenates two strings.
 * @dest: address of first string.
 * @src: address of second string to be concatenated.
 * Return: a string.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i] != '\0')
		i++;
	for (j = 0; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}
	return (dest);
}

/**
 **_strcmp - functions that compares two strings.
 * @s1: address of a string.
 * @s2: address of the second string.
 * Return: integer less than, equal to, or greater than zero.
 * If s1 is found, respectively, to be less than, to match,  or  be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	while ((s1[i] != '\0' || s2[i] != '\0') && j == 0)
	{
		if (s1[i] != s2[i])
		{
			j = (s1[i] - s2[i]);
		}
		i++;
	}
	return (j);
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
	la = malloc(i * sizeof(char)); /*reserve the space of memory*/
	if (!la)
		return (NULL);

	for (j = 0; j < i; j++)
		la[j] = str[j];

	return (la);
}