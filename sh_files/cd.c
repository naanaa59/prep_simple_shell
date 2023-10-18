#include "sh.h"

void t(void);
/**
 * change_dir - changes the directory based on arguments
 *
 * @program_name: the name of executable
 *
 * @line: the line index in shell
 *
 * @command: the command
 *
 * @args: command line in the main function
 *
 * Return: 0 on success and -1 on failure
 */
int change_dir(char **args, char *program_name, int line, char *command)
{
	char *pwd, *oldpwd = NULL, *oldpwd_p = NULL, *home;

	if (args[1] != NULL && ((_strcmp(args[1], "-") != 0)))
	{
		if ((access(args[1], F_OK || (R_OK && W_OK && X_OK))) != 0)
		{
			cd_error(program_name, line, ": can't cd to ", args[1], command);
		}

		pwd = getenv("PWD");
		if ((chdir(args[1])) == 0)
		{
			setenv("OLDPWD", pwd, 1);
			setenv("PWD", args[1], 1);
		}
		else
		{
			return (-1);
		}
	}
	else if (args[1] != NULL && ((_strcmp(args[1], "-") == 0)))
	{
		pwd = getenv("PWD");
		if ((getenv("OLDPWD")) == NULL)
		{
			oldpwd_p = getcwd(NULL, 0);
			oldpwd = oldpwd_p;

		}
		else
		{
			oldpwd = getenv("OLDPWD");
		}
		if ((chdir(oldpwd) == 0))
		{
			_puts(1, oldpwd);
			setenv("OLDPWD", pwd, 1);
			setenv("PWD", oldpwd, 1);
			free(oldpwd_p);
		}
		else
		{
			return (-1);
		}

	}
	else if (args[1] == NULL)
	{
		pwd = getenv("PWD");
		home = getenv("HOME");
		if (home != NULL)
		{
			if ((chdir(home)) == 0)
			{
				setenv("OLDPWD", pwd, 1);
				setenv("PWD", home, 1);
			}
		}
	}
	return (0);
}
/**
 * cd_error - prints the error of "sh: 1: lf: not found"
 *
 * @program_name: the exec name
 *
 * @line: number of the line in sh
 *
 * @command: command name
 *
 * @prefix: first message to print
 *
 * @prefix2: the second message
 */

void cd_error(char *program_name, int line, char *prefix,
		char *prefix2,  char *command)
{

	char *suffix = ": ";
	char *new_line = "\n";


	write(STDERR_FILENO, program_name, _strlen(program_name));
	write(STDERR_FILENO, suffix, _strlen(suffix));
	print_number(2, line);
	write(STDERR_FILENO, suffix, _strlen(suffix));
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, prefix, _strlen(prefix));
	write(STDERR_FILENO, prefix2, _strlen(prefix2));
	write(STDERR_FILENO, new_line, _strlen(new_line));
}
/**
 * t - t
 */
void t(void)
{
}
