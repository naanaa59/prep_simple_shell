#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t _getline(char **line, size_t *n, FILE *file);

ssize_t _getline(char **line, size_t *n, FILE *file)
{
	int fd;
	size_t  nread;

	line = malloc(*n);
	if (line == NULL)
		return (0);
	if (file == NULL)
	{
		free(line);
		return (0);
	}
	fd = open(*file, O_RDONLY);
	if (fd == -1)
	{
		free(line);
		return (0);
	}
	while((nread = read(fd, *line, *n)) > 0)
	{
		if (nread == -1)
			return (0);
	}


	free(line);
}
