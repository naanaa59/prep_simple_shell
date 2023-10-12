#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
    int len, i;
    char **new_environ;
    char *new_variable;

    for (len = 0; environ[len]; len++);
    new_environ = malloc((len + 2) * sizeof(char *));
    if (new_environ == NULL)
        return (-1);
    for (i = 0; i < len; i++)
    {
        new_environ[i] = strdup(environ[i]);
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
    
    for (i = 0; environ[i]; i++)
    {
        free(environ[i]);
    }
    free(environ);

    environ = new_environ;

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
