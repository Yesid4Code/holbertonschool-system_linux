#include "_getline.h"

/**
 * _getline - function that get data from a file line per line.
 * @fd:fd is the file descriptor to read from.
 *
 * Return: a null-terminated string.
 * The string does not include the newline character.
 */
char *_getline(const int fd)
{
	char *line;
	fd_t *file;
	static fd_t *head;

	if (fd == -1)
	{
		free_fd(&head);
		return (NULL);
	}

	file = get_fd(&head, fd);
	if (!file)
		file = add_fd(&head, fd);

	if (file)
		line = get_line(file);
	if (!line)
		free_fd(&head);

	return (line);
}

/**
 * get_fd - function to get the fd.
 * @head: pointer to the head of the list.
 * @fd: fd to find.
 *
 * Return: pointer to the node with the fd, NULL otherwise.
 */
fd_t *get_fd(fd_t **head, const int fd)
{
	fd_t *file = *head;

	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	return (NULL);
}

/**
 * add_fd - function that add a fd as a node in a list.
 * @head: pointer to head of the list.
 * @fd: fd descriptor to add.
 *
 * Return: pointer to the new node added, NULL otherwise.
 */
fd_t *add_fd(fd_t **head, const int fd)
{
	char buff[READ_SIZE];
	fd_t *new, *tmp;

	memset(buff, '\0', READ_SIZE);
	new = malloc(sizeof(fd_t));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->idx = 0;
	new->bytes = read(fd, buff, READ_SIZE);
	if (new->bytes <= 0)
	{
		free(new);
		return (NULL);
	}
	new->buffer = malloc((READ_SIZE + 1) * (sizeof(char)));
	if (!new->buffer)
		return (NULL);
	strncpy(new->buffer, buff, READ_SIZE);
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return (new);
	}

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;

	return (new);
}

/**
 * get_line - Get the line to print.
 * @file: file to search each line.
 *
 * Return: pointer to line, NULL otherwise.
 */
char *get_line(fd_t *file)
{
	int idx = 0, j = 0;
	char *line, *buff; /*[READ_SIZE]; */

	idx = file->idx;
	if (idx >= file->bytes)
		return (NULL);

	buff = malloc(1000 * sizeof(char));
	if (!buff)
		return (NULL);

	while (idx < file->bytes && file->buffer[idx] != '\n')
	{
		buff[j] = file->buffer[idx];
		idx++, j++;
	}
	file->idx = idx + 1;

	line = malloc((j + 1) * sizeof(char));
	if (!line)
		return (NULL);
	memset(line, '\0', (j + 1));
	memcpy(line, buff, j);

	free(buff);
	return (line);
}

/**
 * free_fd - funtion to free each fd and its buffer.
 * @head: pointer to the header of the list.
 */
void free_fd(fd_t **head)
{
	fd_t *tmp;

	while (*head)
	{
		tmp = *head;
		free((*head)->buffer);
		(*head)->buffer = NULL;
		*head = tmp->next;
		free(tmp);
	}
	free(*head);
}
