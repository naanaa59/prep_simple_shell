#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int i;
	pid_t child_pid;
	int status;

	char *args[] = {"./token", "Hello!wor,ld", "!,", NULL};
	for (i = 0; i < 5; i++) {
		child_pid = fork();

		if (child_pid < 0) {
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0) {
			printf("Child %d executing %s:\n", i + 1, args[0]);
			if (execve(args[0], args, NULL) == -1) {
				perror("Execve failed");
				exit(EXIT_FAILURE);
			}
		} else {
			wait(&status);

			if (WIFEXITED(status)) {
				printf("Child %d exited with status %d\n", i + 1, WEXITSTATUS(status));
			} else {
				perror("Child process did not exit normally");
			}
		}
	}

	return 0;
}

