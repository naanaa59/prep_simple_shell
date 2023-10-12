#include "main.h"

#define BUFFER 250

/**
 * main - test function
 *
 * Return : 0
 */
int main(void)
{
	char **command;
	pid_t child_pid;
	int status;

	while (printf("$ ") , (command = get_command()) != NULL)
	{
		child_pid = fork();

		if (child_pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(command[0], command, NULL) == -1)
			{
				perror("Execve failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				printf("\n$ ");
			else
				perror("Child process did not exit normally");
		}
		if (command[0] == NULL)
		{
			printf("\n");
			break;
		}
	free(command);
	}
	return (0);
}
