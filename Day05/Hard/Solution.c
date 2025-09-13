#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool doesAliceWin(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            return true;
        }
    }
    return false;
}

int main() {
    char s[1000];
    scanf("%s", s);
    if (doesAliceWin(s)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
