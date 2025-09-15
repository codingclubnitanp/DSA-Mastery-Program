#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int canBeTypedWords(char *text, char *brokenLetters) {
    bool broken = false;
    int ans = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            if (!broken) ans++;
            broken = false;
        }
        for (int j = 0; j < strlen(brokenLetters); j++) {
            if (text[i] == brokenLetters[j]) {
                broken = true;
            }
        }
    }

    if (!broken) ans++;
    return ans;
}

int main() {
    char *text = "hello world";
    char *brokenLetters = "ad";

    int result = canBeTypedWords(text, brokenLetters);

    printf("Number of words that can be typed: %d\n", result);

    return 0;
}
