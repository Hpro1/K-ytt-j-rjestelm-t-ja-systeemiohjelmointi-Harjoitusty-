#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int count;
    char ch;

    // Iterate over command-line arguments (compressed files)
    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-unzip: cannot open file\n");
            return 1;
        }
        // Read each count and character pair from the file
        while (fread(&count, sizeof(int), 1, fp) == 1) {
            ch = getc(fp); // Get the character
            for (int j = 0; j < count; j++) {
                putc(ch, stdout);
            }
        }
        fclose(fp);
    }
    return 0;
}

