#include "main.h"

int main(int ac, char **av, char **env)
{
	extern char **environ;
	int i;

	printf("global variable enviorn\n"),
	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

	printf("using main function\n");

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);

}
