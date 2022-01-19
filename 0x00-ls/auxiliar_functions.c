#include "headers_ls.h"

/**
 * include - function that search a character in a string.
 * @string: pointer to string.
 * @arg: character to found in string.
 * Return: true or false.
 */
bool include(char *string, char arg)
{
	int i;
	for (i = 0; i < _strlen(string); i++)
	{
		if (string[i] == arg)
			return (true);
	}
	return (false);
}

/**
 * _strlen -  returns the length of a string.
 * @s: pointer to a string.
 * Return: size of the string.
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
 *
 * Return: integer less than, equal to, or greater than zero.
 * If s1 is found, respectively,
 * to be less than, to match,  or  be greater than s2.
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
