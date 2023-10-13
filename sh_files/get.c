#include "sh.h"

void t(void);
void free_grid(char **grid, int size);

/**
 * main - simple shell
 *
 * Return: 0
 */

int main(__attribute__((unused))int argc, char *argv[], char *envp[])
{
	char *command = NULL, *token;
	pid_t child_pid;
	size_t len = 0;
	int status;
	ssize_t nread;
	FILE *stream = stdin;
	char *args[10000];
	int argCount, j, lineIndex = 1, exit_arg = 0, exit_error = 0;
	int found = 0;
	struct stat buffer;

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
	while ((nread = getline(&command,&len, stream)) != -1)
	{
		argCount = 0;
		token = strtok(command, " \n");
		while(token != NULL)
		{
			/*if (stat(token, &buffer) == 0)*/
			args[argCount] = strdup(token);
			/*else*/
			if (args[argCount] == NULL)
			{
				perror("memory allocation failed");
				exit(EXIT_FAILURE);
			}
			argCount++;
			token = strtok(NULL, " \n");
		}
		args[argCount] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			if (argCount > 1)
			{
				exit_arg = atoi(args[1]);
				free(command);
				free_grid(args, argCount);
				exit(exit_arg);
			}
			else
			{
				free(command);
				free_grid(args, argCount);
				exit(exit_error);
			}
		}
		for (j = 0; j < argCount; j++)
		{
			if (stat(args[j], &buffer) == 0)
			{
				child_pid = fork();
				if (child_pid < 0)
				{
					perror("Fork failed");
					exit(EXIT_FAILURE);
				}

				if (child_pid == 0)
				{
					if (execve(args[j], args, envp) == -1)
					{
						perror("Execve failed");
						exit(2);
					}
				}
				else
				{
					wait(&status);
						/*exit_error = status >> 8;*/
					if (WIFEXITED(status))
					{
						/*perror("Child process did not exit normally");*/
						found = 1;
						break;
					}
				}
			}
			else
			{
				exit_error = 2;
			}
		}
		if (!found && args[0] != NULL)
		{
			fprintf(stderr, "%s: %d: %s: command not found\n", argv[0], lineIndex, args[0]);
		}
		/*for (i = 0; i < argCount; i++)
		{
			free(args[i]);
			args[i] = NULL;
		}*/
		free_grid(args, argCount);
		lineIndex++;

		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

	}
	free(command);

	return (0);
}
/**
 * t - t
 */

void t (void)
{
}
/**
 * free_grid - frees a 2 d array
 *
 * @grid: 2d array
 *
 * @size: size of grid
 *
 */
void free_grid(char **grid, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		free(grid[i]);
		grid[i] = NULL;
	}

}
