#include <string.h>
#include <stdio.h>
char *_strtok(char *str, const char *delimiters);
int main(__attribute__((unused)) int ac, char *av[])
{
	char *str, *delim, *token;

	str = av[1];
	delim = av[2];
	token = _strtok(str, delim);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = _strtok(NULL, delim);
	}

	return (0);


}
