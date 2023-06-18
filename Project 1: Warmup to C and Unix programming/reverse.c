#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prints the lines in reverse order and deallocates them
void reverse_print(char **lines, int count, FILE *stream) {
    for (int i = count - 1; i >= 0; i--) {
        fprintf(stream, "%s", lines[i]);
        free(lines[i]);
    }
}

// Resizes the 'lines' array if it's not big enough to store another line
char **resize_if_needed(char **lines, int size) {
    static int capacity = 0;
    if (size > capacity) {
        capacity = (capacity == 0 ? 1 : 2 * capacity);
        lines = realloc(lines, capacity * sizeof(char *));
        if(lines == NULL) {
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
    }
    return lines;
}

int main(int argc, char *argv[]) {
    FILE *in = stdin;
    FILE *out = stdout;
    char **lines = NULL;
    size_t len = 0;
    ssize_t read;
    int line_count = 0;

    // Processing command-line arguments
    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        return 1;
    }

    // Open file streams if file names are provided as command-line arguments
    if (argc >= 2) {
        in = fopen(argv[1], "r");
        if (in == NULL) {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            return 1;
        }

        if (argc == 3) {
            if (strcmp(argv[1], argv[2]) == 0) {
                fprintf(stderr, "Input and output file must differ\n");
                return 1;
            }

            out = fopen(argv[2], "w");
            if (out == NULL) {
                fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
                return 1;
            }
        }
    }

    // Main loop: read lines until EOF or error
    while (1) {
        lines = resize_if_needed(lines, line_count + 1);
        read = getline(&lines[line_count], &len, in);
        if(read == -1){
            break;
        }
        line_count++;
    }

    // Close input file if it was a real file
    if (in != stdin) fclose(in);

    // Print lines in reverse order and deallocate them
    reverse_print(lines, line_count, out);

    // Close output file if it was a real file
    if (out != stdout) fclose(out);

    // Deallocate array of lines
    free(lines);

    return 0;
}

