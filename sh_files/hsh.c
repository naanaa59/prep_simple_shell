#include "sh.h"


void free_grid(char **grid, int size);

/**
 * main - simple shell
 *
 * Return: 0
 */

int main(__attribute__((unused))int argc, char *argv[], char *envp[])
{
	char *command = NULL, *token;
	char *args[10000];
	int argCount, j, lineIndex = 1, found = 0,
	 status = 0, alpha = 0, exit_arg_num, exit_status = 0;
	struct stat buffer;
	pid_t child_pid;
	size_t len = 0;
	ssize_t nread;
	FILE *stream = stdin;
	
	
	
	interactive_mode();
	while ((nread = getline(&command,&len, stream)) != -1)
	{
		argCount = 0;
		token = strtok(command, " \n");
			
		while(token != NULL)
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
			if (argCount > 1)
			{
				alpha = _isalpha_string(args[1]);
				if (alpha == 1)
				{
					custum_perror_exit(argv[0], lineIndex, "exit: Illegal number: ", args[1]);
					free(command);
				    free_grid(args, argCount);
					exit(2);
				}
				else
				{
					exit_arg_num = _atoi(args[1]);
						if (exit_arg_num < 0)
						{
							custum_perror_exit(argv[0], lineIndex, "exit: Illegal number: ", args[1]);
							free(command);
				    		free_grid(args, argCount);
							exit(2);
						}
						else
						{
							free(command);
				    		free_grid(args, argCount);
							exit(exit_arg_num % 256);
						}
				}
			}
			else
			{
				free(command);
				free_grid(args, argCount);
				exit_status = status >> 8;
				exit(exit_status);
			}
		}
		else
		{
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
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					wait(&status);
					if (WIFEXITED(status))
					{
						found = 1;
						break;
					}
				}
			}
			
		}
		
		if (!found && args[0] != NULL)
		{
			custum_perror(argv[0], lineIndex, ": not found", args[0]);
		}
		}
		free_grid(args, argCount);
		lineIndex++;
		interactive_mode();
		

	}
	free(command);

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
