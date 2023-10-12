#include <string.h>

 char *_strtok(char *str, const char *delimiters);

char *_strtok(char *str, const char *delimiters) {
	static char *lastToken = NULL;
	char *tokenStart;
	const char *delimiter;

	if (str != NULL) {
		lastToken = str;
	} else {
		if (lastToken == NULL) {
			return NULL;
		}
		str = lastToken;
	}

	while (*str != '\0' && strchr(delimiters, *str) != NULL) {
		str++;
	}

	if (*str == '\0') {
		return NULL;
	}

	tokenStart = str;

	while (*str != '\0' && strchr(delimiters, *str) == NULL) {
		str++;
	}

	if (*str != '\0') {
		*str = '\0';
		lastToken = str + 1;
	} else {
		lastToken = NULL;
	}

	return tokenStart;
}

