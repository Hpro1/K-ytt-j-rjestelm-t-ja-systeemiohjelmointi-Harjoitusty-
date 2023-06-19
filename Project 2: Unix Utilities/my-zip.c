#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int count = 1;
    char ch, ch_prev;

    // Iterate over command-line arguments (files)
    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-zip: cannot open file\n");
            return 1;
        }

        ch_prev = getc(fp); // Get the first character
        // Read each character of the file
        while ((ch = getc(fp)) != EOF) {
            // If the current character matches the previous character, increment count
            if (ch == ch_prev) {
                count++;
            } else {
                // Write the count and previous character to stdout (compressed output)
                fwrite(&count, sizeof(int), 1, stdout);
                putc(ch_prev, stdout);
                count = 1; // Reset the count for the new character
            }
            ch_prev = ch; // Update the previous character
        }
        fclose(fp);
    }
    return 0;
}

