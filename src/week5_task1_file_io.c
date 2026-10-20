// week5_task1_file_io.c
// Name: ________  Surname: ________  Student ID: ________
//
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
//
// Build: make lab5   Run: ./bin/week5_task1_file_io

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    const char *filename = DEFAULT_FILENAME;
    char line[LINE_LEN];
    int line_count = 0;

    // BONUS: use the file name given on the command line, if any
    if (argc > 1) {
        filename = argv[1];
    }

    // 1. Print message and open the file for writing
    printf("Writing lines to %s...\n", filename);
    fp = fopen(filename, "w");

    // 2. Check that fp is not NULL
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 3. Write a few lines of text
    fprintf(fp, "Hello, file I/O!\n");
    fprintf(fp, "This is the second line.\n");
    fprintf(fp, "And this is the third line.\n");

    // 4. Close the file
    fclose(fp);

    // 5. Open the file again for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 6. Print the contents line by line (and count the lines)
    printf("Reading contents:\n");
    while (fgets(line, LINE_LEN, fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    // 7. Close the file
    fclose(fp);

    // BONUS: print the number of lines
    printf("Lines read: %d\n", line_count);

    return EXIT_SUCCESS;
}