# Reverse Line Reader in C

This repository contains a C program designed to read from an input file or standard input and output the lines in reverse order. It is a powerful utility when you need to analyze data that is written in a line-by-line format, but in a manner where the most recent entries are at the bottom.

The program can handle inputs of arbitrary size, thanks to dynamic memory allocation techniques. It also gracefully manages various error conditions, such as the failure to open a file, the input and output files being the same, or malloc/realloc failure.

## Usage
The program can be invoked in three ways:

1. With no arguments, it reads from standard input and writes to standard output.``./reverse``. (Note: Use CTRL + D to send a EOF)

![](https://github.com/Hpro1/KayttisSysteemiHT/blob/main/Project%201%3A%20Warmup%20to%20C%20and%20Unix%20programming/images/image1.png)

2. With one argument, it reads from the specified input file and writes to standard output. ``./reverse text.txt``

![](https://github.com/Hpro1/KayttisSysteemiHT/blob/main/Project%201%3A%20Warmup%20to%20C%20and%20Unix%20programming/images/image2.png)

3. With two arguments, it reads from the specified input file and writes to the specified output file. ``./reverse text.txt output.txt``

The ``text.txt`` file is The Project Gutenberg EBook of The Adventures of Sherlock Holmes by Sir Arthur Conan Doyle.
[Source to the text](https://norvig.com/big.txt) 

My file is cropped to 105835 lines, 963172 words. 

## Compilation

To compile the program, simply use the gcc compiler with the -o option to specify the output file: ``gcc -o reverse reverse.c``
