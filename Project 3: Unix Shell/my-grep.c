#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Check if the search term and at least one file is provided
    if (argc < 2) {
        printf("my-grep: searchterm [file ...]\n");
        return 1;
    }
    char *searchterm = argv[1];

    // Iterate over command-line arguments (files)
    for (int i = 2; i < argc; i++) {
        // Open the file for reading
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-grep: cannot open file\n");
            return 1;
        }
        // Read each line of the file
        while ((read = getline(&line, &len, fp)) != -1) {
            // Search for the search term in the line
            if (strstr(line, searchterm)) {
                printf("%s", line); // Print the line if a match is found
            }
        }
        fclose(fp);
        if (line) {
            free(line); // Free the allocated memory for line
        }
    }
    return 0;
}

