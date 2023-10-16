#include "sh.h"


void free_grid(char **grid, int size);

/**
 * main - simple shell
 *
 * @argc: arguments count
 *
 * @argv: arguments vector
 *
 * @envp: environ variable
 *
 * Return: 0
 */

int main(__attribute__((unused))int argc, char *argv[], char *envp[])
{
	char *command = NULL, *token;
	char *args[10000];
	int argCount, lineIndex = 1;
	int status = 0;
	/*struct stat buffer;*/
	/*pid_t child_pid;*/
	size_t len = 0;
	ssize_t nread;
	FILE *stream = stdin;



	interactive_mode();
	while ((nread = getline(&command, &len, stream)) != -1)
	{
		argCount = 0;
		token = strtok(command, " \n");
		while (token != NULL)
		{
			args[argCount] = _strdup(token);
			if (args[argCount] == NULL)
			{
				perror("memory allocation failed");
				exit(EXIT_FAILURE);
			}
			argCount++;
			token = strtok(NULL, " \n");
		}
		args[argCount] = NULL;
		if (args[0] != NULL && _strcmp(args[0], "env") == 0)
		{
			print_env(envp);
		}
		else if (args[0] != NULL && _strcmp(args[0], "exit") == 0)
		{
			exit_command(argv, args, argCount, lineIndex, command, &status);
		}
		else if (args[0] != NULL)
		{
			status = exec_command(args, envp, argv, lineIndex);
			
			/*if (!found && args[0] != NULL)
			{
				custom_perror(argv[0], lineIndex, ": not found", args[0]);
			}*/
		}
		free_grid(args, argCount);
		lineIndex++;
		interactive_mode();


	}
	free(command);
	exit(status);
	return (0);
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
