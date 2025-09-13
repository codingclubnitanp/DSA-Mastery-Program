#include <stdio.h>
#include <string.h>

int maxFreqSum(char* s) {
    int n = strlen(s);
    int vowel = 0, conso = 0;
    int freq[256] = {0};

    for (int i = 0; i < n; i++) {
        char c = s[i];
        freq[(int)c]++;
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            if (freq[(int)c] > vowel) vowel = freq[(int)c];
        } else {
            if (freq[(int)c] > conso) conso = freq[(int)c];
        }
    }
    return vowel + conso;
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%d\n", maxFreqSum(s));
    return 0;
}
