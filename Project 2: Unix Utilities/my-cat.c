#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[512];

    // Iterate over command-line arguments (files)
    for (int i = 1; i < argc; i++) {
        // Open the file for reading
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-cat: cannot open file\n");
            return 1;
        }
        // Read and print contents of the file
        while (fgets(buffer, sizeof(buffer), fp)) {
            printf("%s", buffer);
        }
        fclose(fp); // Close the file
    }
    return 0;
}

