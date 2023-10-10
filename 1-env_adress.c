#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[], char *env[]) {
    printf("Address of env parameter: %p\n", (void*)env);
    printf("Address of environ variable: %p\n", (void*)environ);

    if (env == environ) {
        printf("env and environ point to the same location in memory.\n");
    } else {
        printf("env and environ do not point to the same location in memory.\n");
    }

    return 0;
}

