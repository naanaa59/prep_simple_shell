#include "sh.h"
/**
 * exit_command - handle exit command
 * 
 * @args: array of tokens
 * 
 * @argCount: count of tokens
 * 
 * @lineIndex: index of the line in terminal
 * 
 * @command: string of the whole given command
*/
void exit_command(char *argv[], char *args[], int argCount, int lineIndex, char *command, int *status)
{
	int exit_arg_num = 0, exit_status;
	int alpha;

	if (argCount > 1)
			{
				alpha = _isalpha_string(args[1]);
				if (alpha == 1)
				{
					custom_perror_exit(argv[0], lineIndex,
							"exit: Illegal number: ", args[1]);
					free(command);
					free_grid(args, argCount);
					exit(2);
				}
				else
				{
					exit_arg_num = _atoi(args[1]);
					if (exit_arg_num < 0)
					{
						custom_perror_exit(argv[0], lineIndex,
								"exit: Illegal number: ", args[1]);
						free(command);
						free_grid(args, argCount);
						exit(2);
					}
					else
					{
						free(command);
						free_grid(args, argCount);
						exit(exit_arg_num % 256);
					}
				}
			}
			else
			{
				free(command);
				free_grid(args, argCount);
				/*exit_status = status >> 8;*/
                exit_status = *status;
               
				exit(exit_status);
			}
}
int exec_command(char *args[], char *envp[], char *argv[], int lineIndex)
{
    int status ;
	struct stat buffer;
    pid_t child_pid;
    /*int j;*/
    char *full_path;

    
    /*for (j = 0; j < argCount; j++)*/
			/*{*/
           
				if (stat(args[0], &buffer) == 0)
				{
					child_pid = fork();
					/*if (child_pid < 0)
					{
						perror("Fork failed");
						exit(EXIT_FAILURE);
					}*/

					if (child_pid == 0)
					{
						execve(args[0], args, envp);
					}
					else
					{
						wait(&status);
					}
				}
                else 
                {
                    full_path = full_command(args[0]);
                    if (full_path != NULL)
                    {
                        /*_str_replace(&args[j], full_path);*/
                        child_pid = fork();
                        /*if (child_pid < 0)
                        {
                            perror("Fork failed");
                            free(full_path);
                            exit(EXIT_FAILURE);
                        }*/

                        if (child_pid == 0)
                        {
                            
                            execve(full_path, args, envp);
                            free(full_path);
                        }
                        else
                        {
                            wait(&status);
                        }
                        free(full_path);
                    
                    }
                    /*else if (stat(args[0], &buffer) != 0 || !(buffer.st_mode & S_IXUSR))*/
                    else
                    {
                        custom_perror(argv[0], lineIndex, ": not found", args[0]);
                        status = 127;
                    }
                }
            
			/*}*/
           
            return (status);
}
void _str_replace(char **origin, char *new)
{
    free(*origin);
    (*origin) = malloc(_strlen(new + 1));
    _strcpy(*origin, new);
}