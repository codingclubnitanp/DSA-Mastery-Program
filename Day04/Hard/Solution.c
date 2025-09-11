#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isVowel(char ch) {
    return ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U';
}

int cmpfunc(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

void sortVowels(char *s) {
    char vowels[1000];
    int pos[1000], vCount = 0;

    for (int i = 0; s[i]; i++) {
        if (isVowel(s[i])) {
            vowels[vCount] = s[i];
            pos[vCount] = i;
            vCount++;
        }
    }

    qsort(vowels, vCount, sizeof(char), cmpfunc);

    for (int i = 0; i < vCount; i++) {
        s[pos[i]] = vowels[i];
    }
}

int main() {
    char s[1000];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';  // remove newline
    sortVowels(s);
    printf("String after sorting vowels: %s\n", s);
    return 0;
}
