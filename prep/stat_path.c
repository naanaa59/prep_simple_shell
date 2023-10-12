#include "main.h"

int file_exists_in_path(const char *filename)
{
	char *path_var;
	char *path_copy;
	char *path_segment;
	char *full_path;
	struct stat buffer;


	path_var = getenv("PATH");
	if (path_var == NULL) {
		fprintf(stderr, "PATH environment variable not found\n");
		return 0;
	}

	path_copy = strdup(path_var);
	path_segment = strtok(path_copy, ":");

	while (path_segment != NULL) {
		full_path = malloc(strlen(path_segment) + 1 + strlen(filename) + 1);
		if (full_path == NULL) {
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s/%s", path_segment, filename);

		if (stat(full_path, &buffer) == 0) {
			printf("%s\n", full_path);
			free(full_path);
			free(path_copy);
			return 1;
		}

		free(full_path);
		path_segment = strtok(NULL, ":");
	}

	free(path_copy);
	return 0;
}
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    unsigned int i;
    int ret;

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    while (av[i])
    {
	ret = file_exists_in_path(av[i]);
	if (ret != 1)
		printf("not found\n");
	i++;
    }
    return (0);
}
