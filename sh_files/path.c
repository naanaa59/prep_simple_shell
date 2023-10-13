#include "sh.h"

/**
 * ex_in_path - checks if the filename exists in PATH
 *
 * @filename: the name of file
 *
 * Return: 0 on success or -1 on failure
 */

char *full_command(const char *filename)
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
		full_path = malloc(strlen(path_dir) + 1 + strlen(filename) + 1);
		if (full_path == NULL)
			return (NULL);
		strcpy(full_path, path_dir);
		if(full_path[strlen(path_dir) - 1] != '/')
			strcat(full_path, "/");
		strcat(full_path, filename);
		if(stat(full_path, &buffer) != 0)
			return (NULL);
		path_dir = strtok(NULL, ":");
	}
	return (full_path);
}
