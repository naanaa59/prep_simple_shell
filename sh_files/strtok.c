#include "sh.h"

/**
 * t - t
 */

void t(void);

/**
 * _strtok - custumized strtok
 *
 * @str: string with tokens
 *
 * @delimiters: string of delimiters
 *
 * Return: token
 */
char *_strtok(char *str, const char *delimiters)
{
	static char *token;
	static char *nextToken;
	const char *delimiterPtr = delimiters;
	int isDelimiter = 0;
	
	if (str != NULL)
	{
		token = str;
		nextToken = str;
	}
	else if (*nextToken == '\0')
	{
		return (NULL);
	}
	while (*nextToken != '\0')
	{
		while (*delimiterPtr != '\0')
		{
			if (*nextToken == *delimiterPtr)
			{
				isDelimiter = 1;
				break;
			}
			delimiterPtr++;
		}
		if (!isDelimiter)
		{
			break;
		}
		nextToken++;
	}
	token = nextToken;
	while (*nextToken != '\0')
	{
		while (*delimiterPtr != '\0')
		{
			if (*nextToken == *delimiterPtr)
			{
				isDelimiter = 1;
				break;
			}
			delimiterPtr++;
		}

		if (isDelimiter)
		{
			*nextToken = '\0';
			nextToken++;
			return (token);
		}
		nextToken++;
	}
	nextToken = nextToken;
	return (token);
}
void t(void)
{
}



