#include "main.h"

/**
 * _unsetenv - deletes the variable name from envrion
 *
 * @name: the name of the var to delete
 *
 * Return: 0 on success or -1 on error
 */
int _unsetenv(const char *name)
{
	extern char **environ;
	char *var_name;

	char **new_environ;
	int len, i, j = 0, found = 0;

	for(len = 0; environ[len]; len++);
	new_environ = malloc((len  + 1) * sizeof(char *));
	if (new_environ == NULL)
		return -1;

	for (i = 0; i < len; i++)
	{
		var_name = strtok(environ[i], "=");
		if (var_name != NULL && strcmp(name, var_name) != 0)
			new_environ[j++] =  strdup(environ[i]);
		else
		{
			found = 1;
			if (var_name == NULL)
			{
				free(new_environ);
				return (-1);
			}
			free(environ[i]);
		}
	}

	new_environ[j] = NULL;
	if (!found)
	{
		free(new_environ);
		return (-1);
	}
	free(environ);
	environ = new_environ;
	for (i = 0; new_environ[i]; i++)
		free(new_environ[i]);
	free(new_environ);

	return (0);

}
int main(void)
{
	char name[] = "NEW_VAR";
	char value[] = "this is the new value of the new variable";
	char *var = NULL;
	int ret;

	setenv(name, value, 1);
	var = getenv(name);
	printf("%s\n", var);
	ret = _unsetenv("NEW_VAR");
	printf("%d\n", ret);
	return (0);
}
