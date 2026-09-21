#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    char a[100] = "Hello";
    printf("mystrlen: %d\n", mystrlen(a));
    mystrcat(a, ", World");
    printf("mystrcat: %s\n", a);
    char b[100];
    mystrcpy(b, a);
    printf("mystrcpy: %s\n", b);
    char c[10] = {0};
    mystrncpy(c, a, 5);
    printf("mystrncpy: %s\n", c);

    printf("\n--- Testing File Functions ---\n");
    FILE* fp = fopen("test.txt", "r");
    if (!fp) { perror("fopen"); return 1; }
    int l, w, ch;
    if (wordCount(fp, &l, &w, &ch) == 0)
        printf("lines=%d words=%d chars=%d\n", l, w, ch);
    rewind(fp);
    char** m;
    int n = mygrep(fp, "hello", &m);
    printf("matches: %d\n", n);
    for (int i = 0; i < n; i++) { printf("  %s", m[i]); free(m[i]); }
    free(m);
    fclose(fp);
    return 0;
}