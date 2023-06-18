#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000

void reverse_print(char *lines[], int count, FILE *stream) {
    for (int i = count - 1; i >= 0; i--) {
        fprintf(stream, "%s", lines[i]);
        free(lines[i]);
    }
}

int main(int argc, char *argv[]) {
    FILE *in = stdin;
    FILE *out = stdout;
    char *lines[MAX_LINES];
    size_t len = 0;
    ssize_t read;
    int line_count = 0;

    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        return 1;
    }

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

    while ((read = getline(&lines[line_count], &len, in)) != -1) {
        if (++line_count == MAX_LINES) break;
    }

    if (in != stdin) fclose(in);

    reverse_print(lines, line_count, out);

    if (out != stdout) fclose(out);

    return 0;
}

