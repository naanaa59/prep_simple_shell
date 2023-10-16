#include "sh.h"

/**
 * _atoi - convert a string to an integer
 *
 * @s: the string to convert
 *
 * Return: int value of the string
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int i, sign = 1;

	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] == '-')
			sign = sign * -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}

	}
	return (num * sign);
}


/**
 * _strlen - returns the length of a string.
 *
 * @s: given string
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int l = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		l++;
	}
	return (l);
}
/**
 * _puts - prints a string, followed by a new line, to stdout.
 *
 * @str: the given string to print
 *
 * @std: the standard output
 */
void _puts(int std, char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
	{
		_putchar(std, str[i]);
	}
	_putchar(std, '\n');
}
/**
 * _strcpy - copies the string pointed to by src, including the
 * terminating null byte (\0), to the buffer
 *
 * @dest: the destination
 *
 * @src: the source
 *
 * Return: an array of strings
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - concatenates two strings.
 *
 * @dest: is the destination to concatenate to
 *
 * @src: it is the source to concatenate from
 *
 * Return: dest concatenated with src
 */

char *_strcat(char *dest, char *src)
{
	int l_src, l_dest, i;

	for (l_src = 0; src[l_src];)
	{
		l_src++;
	}
	for (l_dest = 0; dest[l_dest];)
	{
		l_dest++;
	}
	for (i = 0; i < l_src; i++)
	{
		dest[l_dest + i] = src[i];
	}
	dest[l_dest + i] = '\0';
	return (dest);
}
