#include <stdio.h>

char *custom_strtok(char *str, const char *delimiters) {
    static char *token; // Keeps track of the current position in the input string
    static char *nextToken; // Keeps track of the next token's position

    if (str != NULL) {
        token = str; // For the first call, initialize the token pointer
        nextToken = str;
    } else if (*nextToken == '\0') {
        return NULL; // End of string
    }

    // Find the beginning of the next token by skipping leading delimiters
    while (*nextToken != '\0') {
        int isDelimiter = 0;
        const char *delimiterPtr = delimiters;
        while (*delimiterPtr != '\0') {
            if (*nextToken == *delimiterPtr) {
                isDelimiter = 1;
                break;
            }
            delimiterPtr++;
        }

        if (!isDelimiter) {
            break; // Found the beginning of the token
        }

        nextToken++;
    }

    token = nextToken; // Set the beginning of the token

    // Find the end of the token
    while (*nextToken != '\0') {
        int isDelimiter = 0;
        const char *delimiterPtr = delimiters;
        while (*delimiterPtr != '\0') {
            if (*nextToken == *delimiterPtr) {
                isDelimiter = 1;
                break;
            }
            delimiterPtr++;
        }

        if (isDelimiter) {
            *nextToken = '\0'; // Replace the delimiter with null terminator
            nextToken++; // Move the nextToken pointer to the next character after the delimiter
            return token; // Found the end of the token
        }

        nextToken++;
    }

    nextToken = nextToken; // End of string
    return token;
}

int main() {
    char str[] = "Hello, World! This is a sample string.";
    const char delimiters[] = " ,.!"; // Delimiters: space, comma, dot, exclamation mark

    char *token = custom_strtok(str, delimiters);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = custom_strtok(NULL, delimiters);
    }

    return 0;
}

