#include <stdlib.h>
#include <stdio.h>


ssize_t _getline(char **line, size_t *n, FILE *file)
{
	ssize_t nread = 0;
	int c;

	if (file == NULL)
		return -1;

	if (*line == NULL || *n == 0) {
		*n = 1024;
		*line = malloc(*n);
		if (*line == NULL)
			return -1;
	}

	while ((c = fgetc(file)) != EOF) {
		(*line)[nread++] = c;
		if (nread >= *n) {
			*n *= 2;
			*line = realloc(*line, *n);
			if (*line == NULL)
				return -1;
		}
		if (c == '\n') {
			break;
		}
	}

	if (c == EOF && nread == 0)
		return -1;
	(*line)[nread++] = '\n';
	(*line)[nread] = '\0';

	return nread - 1;

}

