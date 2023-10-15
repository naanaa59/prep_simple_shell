#include "sh.h"

char *custom_strtok(char *str, const char *delimiters) {
    static char *token; 
    static char *nextToken; 

    if (str != NULL) {
        token = str; 
        nextToken = str;
    } else if (*nextToken == '\0') {
        return NULL; 
    }

   
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
            break; 
        }

        nextToken++;
    }

    token = nextToken; 

    
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
            *nextToken = '\0'; 
            nextToken++; 
            return token; 
        }

        nextToken++;
    }

    nextToken = nextToken;
    return token;
}



