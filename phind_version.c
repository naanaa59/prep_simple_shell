#include "main.h"

char **get_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *token;
	char **command;
	int count = 0;
	size_t i;
	int quotes = 0;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		printf("\n");
		free(line);
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		if (line[i] == '"')
			quotes = !quotes;
		if (line[i] == ' ' && !quotes)
			count++;
	}

	command = (char **)malloc((count + 2) * sizeof(char *));
	if (command == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	i = 0;
	token = strtok(line, " \n");
	while (token != NULL)
	{
		command[i] = strdup(token);
		i++;
		token = strtok(NULL, " \n");
	}
	command[i] = NULL;
	return (command);
}

int main(void)
{
	char **command;
	pid_t child_pid;
	int status;
	size_t i;

	while (printf("$ "), fflush(stdout), (command = get_command()) != NULL)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execvp(command[0], command) == -1)
			{
				perror("execvp failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
				perror("waitpid failed");
				exit(EXIT_FAILURE);
			}
		}
		for (i = 0; command[i] != NULL; ++i)
		{
			free(command[i]);
		}

		free(command);
	}

	return (0);
}

