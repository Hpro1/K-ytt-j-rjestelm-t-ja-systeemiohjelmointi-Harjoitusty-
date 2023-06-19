#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define PATH_SIZE 1024

void execute_command(char *buffer) {
    char *argv[10]; // Array for the command and its arguments
    int argc = 0; // Argument counter

    // Tokenize the command and its arguments
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL; // The array for execvp must be NULL terminated

    // Fork a new process to run the command
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
    } else if (pid == 0) {
        // This is the child process, execute the command
        execvp(argv[0], argv);
        perror("exec failed");
        exit(1);
    } else {
        // This is the parent process, wait for the child to terminate
        wait(NULL);
    }
}

int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [batch_file]\n", argv[0]);
        exit(1);
    }

    // Initialize the command buffer and the default path
    char buffer[BUFFER_SIZE];
    char path[PATH_SIZE] = "/bin";

    while (1) {
        printf("wish> ");

        // Get the command from the user
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            break;
        }

        // Remove the newline at the end of the command
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[--len] = '\0';
        }

        // Check if the command is "exit", "cd", or "path", and handle it accordingly
        if (strcmp(buffer, "exit") == 0) {
            break;
        } else if (strncmp(buffer, "cd", 2) == 0) {
            // Change directory
            char *dir = buffer + 3;
            if (chdir(dir) != 0) {
                perror("cd failed");
            }
        } else if (strncmp(buffer, "path", 4) == 0) {
            // Update the path
            strncpy(path, buffer + 5, PATH_SIZE-1);
            path[PATH_SIZE-1] = '\0';
        } else {
            execute_command(buffer);
        }
    }

    return 0;
}

