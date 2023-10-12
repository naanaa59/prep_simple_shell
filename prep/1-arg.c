#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int c;

	stream = stdin;
	if (stream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while (printf("$ "))
	{
		while ((nread = getline(&line, &len, stream)) != -1)
		{

			fwrite(line, nread, 1, stdout);
			if (line[nread - 1] == '\n')
			{
				line[nread - 1] = '\0';
				printf("$ ");
			}
		}
		if (line[nread - 1] == '\0')
		{
			printf("\n");
			break;
		}


	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
