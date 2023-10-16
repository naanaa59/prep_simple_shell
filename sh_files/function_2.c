#include "sh.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 *
 * @s2: second string
 *
 * Return: It returns an integer less  than,  equal to,
 * or greater than zero if s1 is found, respectively,
 * to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i  = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] == s2[i])
			continue;
		else
			break;

	}

	return (s1[i] - s2[i]);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * @std: the standard output
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int std, char c)
{
	return (write(std, &c, 1));
}
/**
 *_isalpha - Returns 1 if c is a letter, lowercase or uppercase 0 otherwise
 *@c:charachter to test
 *Return: 1 or 0
 */
int _isalpha(int c)
{
	int r = 0;

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		r = 1;
	else
		r = 0;
	return (r);
}
/**
 * interractive_mode - create an interactive mode in sh
 */
void interactive_mode(void)
{
	int t;

	t = isatty(STDIN_FILENO);
	if (t == 1)
	{
		printf("$ ");
		fflush(stdout);
	}
}
/**
 * _strdup - copy of the string given as a parameter.
 *
 * @str: the given string to copy
 *
 * Return: a pointer to the duplicata
 */
char *_strdup(char *str)
{
	char *s;
	int i, j;
	int size = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		size++;
	s = malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	for (j = 0; j < size; j++)
		s[j] = str[j];
	s[j] = '\0';
	return (s);
}
