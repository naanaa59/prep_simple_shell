#include "main.h"

/**
 * get_command - uses getline and strtok to get a command
 *
 * Return: array of strings contains path and arguments of the command
 */

char **get_command(void)
{
	char *line = NULL;
	size_t len = 0, i;
	ssize_t nread;
	char *token;
	char **command;
	int count = 0;

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		for (i = 0; i < len; i++)
		{
			if (line[i] == ' ')
				count++;
		}
		command = (char **)malloc((count + 1) * sizeof(char *));
		if (command == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(1);
		}
		token = strtok(line, " ");
		command[0] = token;
		i = 1;
		while (token != NULL)
		{
			token = strtok(NULL, " ");
			command[i] = token;
			i++;
		}
		command[i] = NULL;
		count = 0;
	}
	free(line);
	return (command);

}
