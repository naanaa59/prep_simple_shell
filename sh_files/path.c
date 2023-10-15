#include "sh.h"

/**
 * ex_in_path - checks if the filename exists in PATH
 *
 * @filename: the name of file
 *
 * Return: 0 on success or -1 on failure
 */

char *full_command(char *filename)
{
	char *path_var;
	char *path_dir;
	char *full_path;
	struct stat buffer;

	if (filename == NULL)
		return (NULL);
	path_var = getenv("PATH");
	if (path_var == NULL)
		return (NULL);

	path_dir = strtok(path_var, ":");
	while (path_dir != NULL)
	{
		full_path = malloc(_strlen(path_dir) + 1 + _strlen(filename) + 1);
		if (full_path == NULL)
			return (NULL);
		_strcpy(full_path, path_dir);
		if(full_path[_strlen(path_dir) - 1] != '/')
			_strcat(full_path, "/");
		_strcat(full_path, filename);
		if(stat(full_path, &buffer) == 0)
			return (full_path);
		path_dir = strtok(NULL, ":");
	}
	return (NULL);
}
