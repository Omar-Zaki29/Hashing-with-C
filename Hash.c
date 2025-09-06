#include <stdio.h>

unsigned int hash_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File openning failed\n", filename);
        return 0;
    }

    unsigned int hash = 0;
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        hash = (hash * 31) + ch;
    }

    fclose(fp);
    return hash;
}

int main(void) {
    char file_name[100];
    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    unsigned int h = hash_file(file_name);
    if (h != 0) {
        printf("Hash of file %s = %u\n", file_name, h);
    }

    return 0;
}

