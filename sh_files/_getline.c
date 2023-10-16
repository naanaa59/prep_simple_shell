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
ssize_t _getline(char **line, size_t *n, FILE *file)
{

	size_t buffer_size = 0;
	ssize_t line_size;



	if (line == NULL || n == NULL)
	{	perror(" line or n are null ");
		return (-1);
	}
	if (*line == NULL || *n == 0)
	{
		/*buffer_size = BUFFER_SIZE;*/
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
	/*line_size = read(file, *line, buffer_size - 1);*/
	fgets(*line, buffer_size, file);


	line_size = _strlen(*line);
	if (line_size > 0 && (*line)[line_size - 1] == '\n')
	{
		(*line)[line_size - 1] = '\0';
		line_size--;
	}
	return (line_size);

}
