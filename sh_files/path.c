#include "sh.h"

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
