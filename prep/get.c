#include "sh.h"

/**
 * main - simple shell
 *
 * Return: 0
 */

int main(__attribute__((unused))int argc,__attribute__((unused)) char *argv[], char *envp[])
{
	char *command = NULL ;
	pid_t child_pid;
	size_t len = 0;
	int status;
	ssize_t nread;
	FILE *stream = stdin;
	char *token;
	char *args[10];
	int argCount = 0, i;

	/*fd = open(stream, O_RDONLY);*/
	if (isatty(fileno(stream)))
	{
		printf("Interactive shell mode.\n");
	}
	else
	{
		printf("Non-interactive mode\n");
	}
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
	while ((nread = getline(&command,&len, stream)) != -1)
	{
		token = strtok(command, " \n");
		while(token != NULL)
		{
			args[argCount] = strdup(token);
			if (args[argCount] == NULL)
			{
				perror("memory allocation failed");
				for (i = 0; i < argCount; i++)
				{
					free(args[i]);
				}
				free(command);
				exit(EXIT_FAILURE);
			}
			/*printf("%s ",args[argCount]);*/
			argCount++;
			token = strtok(NULL, " \n");
		}
		args[argCount] = NULL;
		/*if (args[argCount - 1] == "\n")*/
		child_pid = fork();

		if (child_pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(args[0], args, envp) == -1)
			{ 	printf("that s my args[0]: %s", args[0]);
				perror("Execve failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				printf("$ ");
			else
				perror("Child process did not exit normally");
		}


	}
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
	return (0);
}
