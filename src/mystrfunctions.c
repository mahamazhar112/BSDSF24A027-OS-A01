#include "../include/mystrfunctions.h"

int mystrlen(const char* s) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int mystrcpy(char* dest, const char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
    return i;
}

int mystrncpy(char* dest, const char* src, int n) {
    int i = 0;
    while (i < n && src[i] != '\0') { dest[i] = src[i]; i++; }
    int copied = i;
    while (i < n) dest[i++] = '\0';
    return copied;
}

int mystrcat(char* dest, const char* src) {
    int d = mystrlen(dest), i = 0;
    while ((dest[d + i] = src[i]) != '\0') i++;
    return d + i;
}