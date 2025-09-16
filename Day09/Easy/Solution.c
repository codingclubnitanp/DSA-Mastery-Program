#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s) {
    int left = 0, right = strlen(s) - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }
    return true;
}

int main() {
    char s[] = "A man, a plan, a canal: Panama";
    printf("%s\n", isPalindrome(s) ? "true" : "false");
    return 0;
}
