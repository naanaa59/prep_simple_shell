#include "main.h"

/**
 * _setenv - changes or adds an environment variable
 *
 * @name: the name of variable
 *
 * @value: value of the var
 *
 * @overwrite: order to overwrite if nonzero
 *
 * Return: 0 on success or -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char *new_value = NULL, *name_env = NULL, **new_environ, *new_variable = NULL;
	int i, len;
	size_t length;



	if (name == NULL || value == NULL || strchr(name, '=') != NULL)
		return (-1);
	length = strlen(name) + strlen(value) + 2;
	for (i = 0; environ[i]; i++)
	{
		name_env = strtok(environ[i], "=");
		if (strcmp(name, name_env) == 0)
		{
			if (overwrite != 0)
			{
				new_value = malloc(length);
				if (new_value == NULL)
					return (-1);

				sprintf(new_value, "%s=%s", name, value);
				environ[i] = new_value;
				free(new_value);
				return (0);
			}
			return (0);

		}
	}
	for (len = 0; environ[len]; len++);
	new_environ = malloc((len + 2) * sizeof(char *));
	if (new_environ == NULL)
		return (-1);
	for (i = 0; i < len; i++)
	{
		new_environ[i] = environ[i];
	}
	new_variable = malloc(strlen(name) + strlen(value) + 2);
	if (new_variable == NULL)
	{
		free(new_environ);
		return (-1);
	}
	sprintf(new_variable, "%s=%s", name, value);
	new_environ[len] = new_variable;
	new_environ[len + 1] = NULL;

	/*free(environ);*/
	environ = new_environ;
	free(new_variable);

	return (0);

}
int main(void)
{
	char name[] = "NEW_VAR";
	char value1[] = "this is the new value of the new variable";
	char value2[] = "this is the 2 new value of the new variable";
	char *var = NULL;

	_setenv(name, value1, 1);
	var = getenv(name);
	printf("%s\n", var);
	_setenv(name, value2, 1);
	var = getenv(name);
	printf("%s\n", var);

	return (0);
}
