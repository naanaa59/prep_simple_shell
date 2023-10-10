#include "main.h"

char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	char *name_env = NULL;
	char *value = NULL;
	char *environ_cpy = NULL;


	for (i = 0; environ[i]; i++)
	{
		environ_cpy = strdup(environ[i]);
		name_env= strtok(environ_cpy, "=");
		value = strchr(environ[i], '=');

		if (strcmp(name, name_env) == 0)
		{
			free(environ_cpy);
			return(++value);
		}
	}
	free(environ_cpy);
	return (NULL);
}

int main(void)
{
	char *name;
	char *value = NULL;
	char *dir = NULL;
	char *value_cpy = NULL;

	name = "PATH";
	value = _getenv(name);

	if (value != NULL)
	{
		value_cpy = strdup(value);
		dir = strtok(value_cpy, ":");
		while (dir)
		{
			printf("%s\n", dir);
			dir = strtok(NULL, ":");
		}
		free(value_cpy);
	}
	return (0);
}
