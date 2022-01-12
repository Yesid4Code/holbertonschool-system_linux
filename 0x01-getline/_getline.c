#include "_getline.h"
/**
 * _getline -
 * @fd:fd is the file descriptor to read from.
 *
 * Return: a null-terminated string that does not include the newline character.
 */
char *_getline(const int fd)
{
	char *line = NULL;
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

	line = get_line(file);
	if (!line)
		free_fd(&head);

	// sleep(1);
	return (line);
}

fd_t *get_fd(fd_t **head, const int fd)
{
	fd_t *file = *head;

	while (file)
	{
		if (file->fd == fd)
			return file;
	}
	return (NULL);
}

fd_t *add_fd(fd_t **head, const int fd)
{
	char buff[READ_SIZE];
	fd_t *new, *tmp = *head;

	memset(buff, 0, READ_SIZE);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->idx = 0;
	new->bytes = read(fd, buff, READ_SIZE);
	new->buffer = malloc(new->bytes * (sizeof(char)));
	if (!new->buffer)
		return (NULL);
	memcpy(new->buffer, buff, new->bytes);
	//new->buffer[new->bytes + 1] = '\0';
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return (new);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;

	return (new);
}

char *get_line(fd_t *file)
{
	int idx = 0, j = 0;
	char *line = NULL, buff[READ_SIZE];

	idx = file->idx;
	if (idx >= file->bytes)
	{
		return (NULL);
	}
	
	while (idx < file->bytes && file->buffer[idx] != '\n')
	{
		buff[j] = file->buffer[idx];
		idx++, j++;
	}
	file->idx = idx + 1;
	line = malloc(j * sizeof(char) + 1);
	memcpy(line, buff, j);

	return (line);
}

void free_fd(fd_t **head)
{
	fd_t *tmp = *head;

	while (*head)
	{
		tmp = *head;
		free((*head)->buffer), free(*head);
		*head = tmp->next;
	}
	//free(head);
}