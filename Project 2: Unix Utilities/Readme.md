# Unix Utilities in C

The source this is based on [is here](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-utilities)

This project aims to build a collection of Unix utilities using the C programming language. The utilities implemented include my-cat, my-grep, my-zip, and my-unzip, which are simplified versions of commonly used commands like cat, grep, zip, and unzip.

## Project Objectives
- Re-familiarize with C programming language
- Gain proficiency in using shell/terminal/command-line of Unix systems
- Learn how to use a code editor like Emacs
- Understand the implementation of Unix utilities

## Usage
### my-cat.c
The my-cat program reads one or more files specified by the user and prints their contents to the console.
![](https://github.com/Hpro1/KayttisSysteemiHT/blob/main/Project%202%3A%20Unix%20Utilities/images/my-cat.png)

### my-grep.c
The my-grep program searches for a user-specified search term in one or more files and prints the matching lines.
![](https://github.com/Hpro1/KayttisSysteemiHT/blob/main/Project%202%3A%20Unix%20Utilities/images/my-grep.png)

### my-zip.c
The my-zip program implements a simple compression algorithm called run-length encoding (RLE). It compresses input files by replacing consecutive repeated characters with a count and the character itself.
![](https://github.com/Hpro1/KayttisSysteemiHT/blob/main/Project%202%3A%20Unix%20Utilities/images/my-zip.png)

### my-unzip.c
The my-unzip program is the counterpart of my-zip and decompresses files compressed with the RLE algorithm, restoring them to their original form.
![](https://github.com/Hpro1/KayttisSysteemiHT/blob/main/Project%202%3A%20Unix%20Utilities/images/my-unzip.png)


## Compilation 
Each utility is implemented as a separate C file: my-cat.c, my-grep.c, my-zip.c, and my-unzip.c. You can compile each program using ``gcc`` and run them from the command line. For example: ``gcc -o my-grep my-grep.c``
