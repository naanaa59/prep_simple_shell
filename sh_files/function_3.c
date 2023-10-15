#include "sh.h"
/**
 * print_number - prints an integers
 *
 * @n: the integer to be printed
 */
void print_number(int std, int n)
{
	unsigned int i;

	if (n < 0)
	{
		_putchar(std, '-');
		i = -n;
	}
	else
	{
		i = n;
	}
	if (i / 10)
		print_number(std, i / 10);
	_putchar(std, i % 10 + '0');
}
/**
 * p_nfound - prints the error of "sh: 1: lf: not found"
 * 
 * @program_name: the exec name
 * 
 * @line: number of the line in sh
 * 
 * @command: command name
*/

void custum_perror(char *program_name, int line, char *prefix, char *command)
{
    
    char *suffix = ": ";
    char *new_line = "\n";

    
    write(STDERR_FILENO, program_name, _strlen(program_name));
    write(STDERR_FILENO, suffix, _strlen(suffix));
    print_number(2, line);
    write(STDERR_FILENO, suffix, _strlen(suffix));
    write(STDERR_FILENO, command, _strlen(command));
    write(STDERR_FILENO, prefix, _strlen(prefix));
    write(STDERR_FILENO, new_line, _strlen(new_line));
}

void custum_perror_exit(char *program_name, int line, char *prefix, char *command)
{
    
    char *suffix = ": ";
    char *new_line = "\n";

    
    write(STDERR_FILENO, program_name, _strlen(program_name));
    write(STDERR_FILENO, suffix, _strlen(suffix));
    print_number(2, line);
    write(STDERR_FILENO, suffix, _strlen(suffix));
    write(STDERR_FILENO, prefix, _strlen(prefix));
    write(STDERR_FILENO, command, _strlen(command));
    write(STDERR_FILENO, new_line, _strlen(new_line));
}
/**
 * _isalpha_string - checks a whole string with _isalpha
 * 
 * @arg: the given string to checks
 * 
 * Return: 1 is a letter is found or 0 otherwise
*/
int _isalpha_string (char *arg)
{
    int i, alpha, r;

    for (i = 0; arg[i]; i++)
    {
        alpha = _isalpha(arg[i]);
    }
    if (alpha == 1)
    {
            r = 1;
    }
    else if (alpha == 0)
    {
        r = 0;
    }
    return (r);
}

/**
 * print_grid - prints a 2D array of char
 * 
 * @grid: the 2D array of char to print
 * 
*/
void print_env(char **env)
{
    int env_size = 0, i;
    char **env_cpy = NULL;

    for (i = 0; env[i]; i++)
    {
        env_size += _strlen(env[i]) + 1;
    }
    env_cpy = malloc((env_size + 1) * sizeof(char));

    for (i = 0; env[i]; i++)
    {
    env_cpy[i] = (char *)malloc(_strlen(env[i]) + 1 * sizeof(char));
    _strcpy(env_cpy[i], env[i]);
    }
    env_cpy[i] = NULL;
    
    for (i = 0; env_cpy[i]; i++)
    {
        _puts(1, env_cpy[i]);
    }
    _putchar(1, '\n');
     for (i = 0; env_cpy[i]; i++)
    {
        free(env_cpy[i]);
    }
    free(env_cpy);
}

