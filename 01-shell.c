#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char *command = NULL;
    size_t command_size = 0;
    ssize_t characters_read;

    pid_t pid;

    while (1) {
        /* Display prompt */
        write(STDOUT_FILENO, "#cisfun$ ", 14);

        /* Read user input using getline */
        characters_read = getline(&command, &command_size, stdin);

        if (characters_read == -1) {
            /* Handle end of file (Ctrl+D) */
            write(STDOUT_FILENO, "\nExiting shell...\n", 18);
            free(command);
            break;
        }

        /* Remove trailing newline character */
        command[characters_read - 1] = '\0';

        /* Fork a child process */
        pid = fork();

        if (pid < 0) {
            /* Fork failed */
            perror("Fork failed");
            free(command);
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */
            /* Execute the command */
            if (execlp(command, command, (char *)NULL) == -1) {
                /* Handle command not found */
                perror("Error");
                free(command);
                exit(EXIT_FAILURE);
            }
        } else {
            /* Parent process */
            /* Wait for the child process to finish */
            wait(NULL);
        }
    }

    return 0;
}
