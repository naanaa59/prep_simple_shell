#include "sh.h"

/**
 * exit_command - handle exit command
 *
 * @args: array of tokens
 *
 * @argCount: count of tokens
 *
 * @lineIndex: index of the line in terminal
 *
 * @argv: arguments vector from main
 *
 * @status: the status of the child pid
 *
 * @command: string of the whole given command
 */
void exit_command(char *argv[], char *args[], int argCount,
		int lineIndex, char *command, int *status)
{
	int exit_arg_num = 0, exit_status;
	int alpha;

	if (argCount > 1)
	{
		alpha = _isalpha_string(args[1]);
		if (alpha == 1)
		{
			custom_perror_exit(argv[0], lineIndex,
					"exit: Illegal number: ", args[1]);
			free(command);
			free_grid(args, argCount);
			exit(2);
		}
		else
		{
			exit_arg_num = _atoi(args[1]);
			if (exit_arg_num < 0)
			{
				custom_perror_exit(argv[0], lineIndex,
						"exit: Illegal number: ", args[1]);
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
		exit_status = *status;
		exit(exit_status);
	}
}

/**
 * exec_command - execute the given command
 *
 * @args: strings containing the tokens from command line
 *
 * @envp: environ variable
 *
 * @argv: arg vector of main function
 *
 * @lineIndex: index of the command line in Interc mode
 *
 * Return: the status
 */
int exec_command(char *args[], char *envp[], char *argv[], int lineIndex)
{
	int status;
	struct stat buffer;
	pid_t child_pid;
	char *full_path;

	if (stat(args[0], &buffer) == 0)
	{
		child_pid = fork();
		if (child_pid == 0)
			execve(args[0], args, envp);
		else
			wait(&status);
	}
	else
	{
		full_path = full_command(args[0]);
		if (full_path != NULL)
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				execve(full_path, args, envp);
				free(full_path);
			}
			else
				wait(&status);
			free(full_path);
		}
		else
		{
			status = 127;
			custom_perror(argv[0], lineIndex, ": not found", args[0]);
		}
	}
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
	}
	return (status);
}
/**
 * full_command - checks if the filename exists in PATH
 *
 * @filename: the name of file
 *
 * Return: string with all the path
 */

char *full_command(char *filename)
{
	char *path_var;
	char *path_dir;
	char *full_path;
	char *path_copy;
	struct stat buffer;

	if (filename == NULL)
		return (NULL);
	path_var = getenv("PATH");
	if (path_var == NULL)
		return (NULL);
	path_copy = _strdup(path_var);
	if (path_copy == NULL)
		return (NULL);
	path_dir = strtok(path_copy, ":");
	while (path_dir != NULL)
	{
		full_path = malloc(_strlen(path_dir) + 1 + _strlen(filename) + 1);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		_strcpy(full_path, path_dir);

		if (full_path[_strlen(path_dir) - 1] != '/')
			_strcat(full_path, "/");

		_strcat(full_path, filename);

		if (stat(full_path, &buffer) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		path_dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
