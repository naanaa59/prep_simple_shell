#include "sh.h"


#define BUFFER_SIZE 1024
/**
 * _getline - custumizes version of getline
 *
 * @line: pointer to the line to read
 *
 * @n: size of the line
 *
 * @file: the file to read from
 *
 * Return: size of the line
 */
ssize_t _getline(char **line, size_t *n)
{
	ssize_t line_size = 0;
	size_t buffer_size = 0;


	if (line == NULL || n == NULL)
	{	perror(" line or n are null ");
		return (-1);
	}
	if(*line == NULL || *n == 0)
	{
		buffer_size = BUFFER_SIZE;
		*line = (char *)malloc(buffer_size);
		if (*line == NULL)
		{
			perror("memory allocation failed");
			return (-1);
		}
		*n = buffer_size;
	}
		else
			buffer_size = *n;
	line_size = read(STDIN_FILENO, *line, buffer_size - 1);
	if (line_size == -1)
	{
		perror("read function failed");
		return (-1);
	}
	(*line)[line_size] = '\0';

	return (line_size);

}
