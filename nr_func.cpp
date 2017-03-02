#include "nr_func.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

unsigned int nr_func::nr_indexof(const char *haystack, const char *needle) {
    return strstr(haystack, needle) - haystack;
}


char *nr_func::nr_substr(const char* str, int start, int end) {
    char *output = (char *)malloc((size_t) (1 + (end - start)));
    memcpy(output, str+start, (size_t)(end-start));
    output[(end-start)] = '\0';
    return output;
}


bool nr_func::nr_equals(const char *str1, const char *str2) {
    unsigned int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 != len2) return false;
    unsigned int minlen = len1 < len2 ? len1 : len2;
    for (int i = 0; i < minlen; ++i) {
        if (str1[i] != str2[i]) return false;
    }
    return true;
}
