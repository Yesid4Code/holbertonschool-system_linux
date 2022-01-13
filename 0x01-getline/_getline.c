#include "_getline.h"
/**
 * _getline -
 * @fd:fd is the file descriptor to read from.
 *
 * Return: a null-terminated string that does not include the newline character.
 */
char *_getline(const int fd)
{
	char *line;
	fd_t *file;
	static fd_t *head;

	if (fd == -1)
	{
		//free_fd(&head);
		return (NULL);
	}

	file = get_fd(&head, fd);
	if (!file)
		file = add_fd(&head, fd);

	if (file)
		line = get_line(file);
	if (!line)
		free_fd(&head);
	//printf("\n\nSIZE OF FD_T: %lu\n\n", sizeof(file->buffer));

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
	fd_t *new, *tmp;

	memset(buff, 0, READ_SIZE);
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
	new->buffer = malloc((new->bytes + 1) * (sizeof(char)));
	if (!new->buffer)
		return (NULL);
	//memset(new->buffer, 0, new->buffer + 1);
	strcpy(new->buffer, buff);
	//new->buffer[new->bytes + 1] = '\0';
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

char *get_line(fd_t *file)
{
	int idx = 0, j = 0;
	char *line, buff[READ_SIZE];

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
	memset(line, '\0', j);
	if (!line)
		return (NULL);
	memcpy(line, buff, j);

	return (line);
}

void free_fd(fd_t **head)
{
	fd_t *tmp;

	while (*head)
	{
		tmp = *head;
		free((*head)->buffer);
		(*head)->buffer = NULL;//free((*head)->next);
		//free(*head);
		*head = tmp->next;
		free(tmp);
	}
	free(*head);
}
//valgrind-- leak - check = full-- show - leak - kinds = all-- track - origins = yes - s./ a.out