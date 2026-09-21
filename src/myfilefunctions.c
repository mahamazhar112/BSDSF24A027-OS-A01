#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file || !lines || !words || !chars) return -1;
    *lines = *words = *chars = 0;
    int c, in_word = 0;
    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if (c == ' ' || c == '\n' || c == '\t') in_word = 0;
        else if (!in_word) { in_word = 1; (*words)++; }
    }
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1;
    char* line = NULL;
    size_t cap = 0;
    int count = 0;
    *matches = NULL;
    while (getline(&line, &cap, fp) != -1) {
        if (strstr(line, search_str)) {
            char** tmp = realloc(*matches, (count + 1) * sizeof(char*));
            if (!tmp) { free(line); return -1; }
            *matches = tmp;
            (*matches)[count++] = strdup(line);
        }
    }
    free(line);
    return count;
}